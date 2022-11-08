add_rules("mode.debug", "mode.release")

target("LovenseToys")
    set_kind("static")

    add_files("lib/LovenseToys.lib")

target("Lovense")
    set_kind("binary")
    add_files("src/*.cpp")
    add_deps("LovenseToys")