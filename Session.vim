let SessionLoad = 1
let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/Documents/projects/nand2tetris/jack_compiler
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
let s:shortmess_save = &shortmess
set shortmess+=aoO
badd +950 src/CompilationEngine.cpp
badd +66 src/VmWritter.cpp
badd +63 src/SymbolTable.cpp
badd +1 .clang-format
badd +25 ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
badd +19 test/files/compilation/converttobin_main.vm
badd +13 Main.vm
badd +1 templates/writePushTemplate.txt
badd +73 include/CompilationEngine.hpp
badd +1 templates/writeIfTemplate.txt
badd +1 templates/writeGotoTemplate.txt
argglobal
%argdel
set stal=2
tabnew +setlocal\ bufhidden=wipe
tabnew +setlocal\ bufhidden=wipe
tabrewind
edit src/SymbolTable.cpp
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 26 + 27) / 54)
exe 'vert 1resize ' . ((&columns * 81 + 42) / 85)
exe '2resize ' . ((&lines * 24 + 27) / 54)
exe 'vert 2resize ' . ((&columns * 81 + 42) / 85)
exe 'vert 3resize ' . ((&columns * 1 + 42) / 85)
exe 'vert 4resize ' . ((&columns * 1 + 42) / 85)
argglobal
balt src/VmWritter.cpp
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=4
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
49
sil! normal! zo
52
sil! normal! zo
54
sil! normal! zo
65
sil! normal! zo
91
sil! normal! zo
91
sil! normal! zo
let s:l = 63 - ((13 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 63
normal! 020|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp | else | edit ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp
endif
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=2
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
1
sil! normal! zo
14
sil! normal! zo
70
sil! normal! zo
let s:l = 75 - ((14 * winheight(0) + 12) / 24)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 75
normal! 019|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/src/CompilationEngine.cpp", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/src/CompilationEngine.cpp | else | edit ~/Documents/projects/nand2tetris/jack_compiler/src/CompilationEngine.cpp | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/src/CompilationEngine.cpp
endif
balt ~/Documents/projects/nand2tetris/jack_compiler/src/VmWritter.cpp
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=7
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
299
sil! normal! zo
327
sil! normal! zo
333
sil! normal! zo
349
sil! normal! zo
494
sil! normal! zo
let s:l = 1113 - ((0 * winheight(0) + 25) / 51)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1113
normal! 017|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack | else | edit ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
endif
balt ~/Documents/projects/nand2tetris/jack_compiler/src/CompilationEngine.cpp
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 41 - ((34 * winheight(0) + 25) / 51)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 020|
lcd ~/Documents/courses/nand2tetris/projects/11/ConvertToBin
wincmd w
exe '1resize ' . ((&lines * 26 + 27) / 54)
exe 'vert 1resize ' . ((&columns * 81 + 42) / 85)
exe '2resize ' . ((&lines * 24 + 27) / 54)
exe 'vert 2resize ' . ((&columns * 81 + 42) / 85)
exe 'vert 3resize ' . ((&columns * 1 + 42) / 85)
exe 'vert 4resize ' . ((&columns * 1 + 42) / 85)
tabnext
edit ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 3resize ' . ((&columns * 84 + 42) / 85)
argglobal
balt ~/Documents/projects/nand2tetris/jack_compiler/Main.vm
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 46 - ((17 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 46
normal! 05|
lcd ~/Documents/courses/nand2tetris/projects/11/ConvertToBin
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/Main.vm", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/Main.vm | else | edit ~/Documents/projects/nand2tetris/jack_compiler/Main.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/Main.vm
endif
balt ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm
setlocal foldmethod=diff
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 70 - ((51 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 70
normal! 015|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm | else | edit ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm
endif
balt ~/Documents/projects/nand2tetris/jack_compiler/Main.vm
setlocal foldmethod=diff
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=1
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 57 - ((38 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 57
normal! 015|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
exe 'vert 3resize ' . ((&columns * 84 + 42) / 85)
tabnext
edit ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
2wincmd h
wincmd w
wincmd w
let &splitbelow = s:save_splitbelow
let &splitright = s:save_splitright
wincmd t
let s:save_winminheight = &winminheight
let s:save_winminwidth = &winminwidth
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 48 + 42) / 85)
argglobal
enew
file ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/NvimTree_3
balt ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm
setlocal foldmethod=manual
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal nofoldenable
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
argglobal
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 42 - ((21 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 42
normal! 013|
lcd ~/Documents/courses/nand2tetris/projects/11/ConvertToBin
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm | else | edit ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm
endif
balt ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
setlocal foldmethod=expr
setlocal foldexpr=v:lua.vim.treesitter.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
let s:l = 11 - ((10 * winheight(0) + 26) / 53)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 11
normal! 0
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
exe 'vert 1resize ' . ((&columns * 48 + 42) / 85)
tabnext 1
set stal=1
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0 && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20
let &shortmess = s:shortmess_save
let &winminheight = s:save_winminheight
let &winminwidth = s:save_winminwidth
let s:sx = expand("<sfile>:p:r")."x.vim"
if filereadable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
