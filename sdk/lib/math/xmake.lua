-- Copyright CHERIoT Contributors.
-- SPDX-License-Identifier: MIT

local mathdir = os.scriptdir()
local mathheader = path.join(mathdir, "math.h")

local msundir = "../../third_party/msun"

library("math")
set_default(false)
add_cxflags("-include " .. mathheader)
add_includedirs(mathdir)
add_defines("__SOFTFP__")
add_deps("softfloatall")
add_files(path.join(msundir, "e_sqrt.c"))
add_files(path.join(msundir, "e_sqrtf.c"))
add_files(path.join(msundir, "e_log.c"))
add_files(path.join(msundir, "e_log2.c"))
add_files(path.join(msundir, "e_log2f.c"))
add_files(path.join(msundir, "e_log10.c"))
add_files(path.join(msundir, "e_log10f.c"))
add_files(path.join(msundir, "e_logf.c"))
add_files(path.join(msundir, "e_exp.c"))
add_files(path.join(msundir, "e_expf.c"))
add_files(path.join(msundir, "s_exp2.c"))
add_files(path.join(msundir, "s_exp2f.c"))
