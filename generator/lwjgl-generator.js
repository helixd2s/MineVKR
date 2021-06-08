let lwjglVersion = "3.3.0";

let lwjglLibraries = [
    {
        "name": `org.lwjgl:lwjgl-glfw:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-jemalloc:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-openal:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-opengl:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-stb:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-tinyfd:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-tinyfd:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-vulkan:${lwjglVersion}`,
        "natives": {
            //"linux": "natives-linux",
            "osx": "natives-macos",
            //"windows": "natives-windows"
        }
    },
    {
        "name": `org.lwjgl:lwjgl-vma:${lwjglVersion}`,
        "natives": {
            "linux": "natives-linux",
            "osx": "natives-macos",
            "windows": "natives-windows"
        }
    }
];

let meta = {
    "name": "LWJGL 3",
    "releaseTime": "2019-06-24T12:52:52+00:00",
    "type": "release",
    "uid": "org.lwjgl3",
    "version": lwjglVersion,
    "volatile": true  
};

/*
let meta = {
    "name": "LWJGL 3",
    "releaseTime": "2020-05-18T12:01:01+00:00", // TODO: Update TIME!
    "type": "release",
    "uid": "org.lwjgl3",
    "version": lwjglVersion,
    "volatile": true
};
*/

const crypto = require('crypto')
const path = require('path');
const util = require('util'), fs = require('fs')

const mkdir = util.promisify(fs.mkdir);



function checksum(binary, algorithm, encoding) {
  return crypto
    .createHash(algorithm || 'sha1')
    .update(binary, encoding || 'binary')
    .digest('hex')
}

function copyFileSync( source, target ) {
    var targetFile = target;
    if ( fs.existsSync( target ) ) {
        if ( fs.lstatSync( target ).isDirectory() ) {
            targetFile = path.join( target, path.basename( source ) );
        }
    }
    fs.writeFileSync(targetFile, fs.readFileSync(source));
}

async function copyFile(source, target) {
    fs.mkdirSync(path.dirname(target), { recursive: true });
    copyFileSync(source, target);
}


function generate(rpath) {
    let json = {"formatVersion": 1, "libraries":[]};

    // Attemp to FIX
    /*json.libraries.push({
        "downloads": {
            "artifact": {
                "sha1": "d3ad4df38e400b8afba1de63f84338809399df5b",
                "size": 108907,
                "url": "https://libraries.minecraft.net/org/lwjgl/lwjgl-glfw/3.2.2/lwjgl-glfw-3.2.2.jar"
            }
        },
        "name": "org.lwjgl:lwjgl-glfw:3.2.2"
    });*/

    let I = 0; 
    for (let lib of lwjglLibraries) { let i = I++;
        let parts = lib.name.split(":");
        let dir = parts[0].replace(".","/");
        let name = parts[1];
        let version = parts[2];
        let dpath = path.normalize(path.resolve(rpath + "/.." + "/" + dir + "/" + name + "/" + version + "/" + name + "-" + version + ".jar"));
        //let fpath = dpath + "/" + dir + name + "-" + version;
        //let fpath = dpath + "/" + dir + name;
        let fpath = path.normalize(path.resolve(rpath + "/" + name + ".jar"));
        let fdata = fs.readFileSync(fpath);
        let sha1 = checksum(fdata);
        
        copyFile(fpath, dpath);

        // 
        let library = Object.assign({}, lib);
        library.downloads = {
            "artifact": {
                "sha1": sha1,
                "size": fdata.byteLength,
                "url": "file:///" + dpath.replace(/\\/g,"/")
            },
            "classifiers": {}
        };

        //if (i == 0) {
            json.libraries.push({
                "name": lib.name,
                "downloads": {
                    "sha1": sha1,
                    "size": fdata.byteLength,
                    "url": "file:///" + dpath.replace(/\\/g,"/")
                }
            });
        //}

        // 
        for (let nat in lib.natives) {
            let suffix = lib.natives[nat];
            let dpath = path.normalize(path.resolve(rpath + "/.." + "/" + dir + "/" + name + "/" + version + "/" + name + "-" + version + "-" + suffix + ".jar"));
            //let fpath = dpath + "/" + dir + name + "-" + suffix;
            let fpath = path.normalize(path.resolve(rpath + "/" + name + "-" + suffix + ".jar"));
            let fdata = fs.readFileSync(fpath);
            let sha1 = checksum(fdata);
            
            copyFile(fpath, dpath);

            library.downloads.classifiers["natives-"+nat] = {
                "sha1": sha1,
                "size": fdata.byteLength,
                "url": "file:///" + dpath.replace(/\\/g,"/")
            };
        }

        json.libraries.push(library);
    }

    json = Object.assign(json, meta);
    console.log(JSON.stringify(json, null, '\t'));

    fs.writeFileSync("org.lwjgl3.json", JSON.stringify(json, null, '\t'), 'utf8');
};

generate(process.argv[2] + "\\" + lwjglVersion);
//generate(__dirname.replace(/\\/g,"/") + "/" + lwjglVersion);
