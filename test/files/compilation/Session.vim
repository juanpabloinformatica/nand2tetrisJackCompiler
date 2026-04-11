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
badd +1 src/SymbolTable.cpp
badd +1 .clang-format
badd +26 ~/Documents/courses/nand2tetris/projects/11/ConvertToBin/Main.jack
badd +11 test/files/compilation/converttobin_main.vm
badd +13 Main.vm
badd +1 templates/writePushTemplate.txt
badd +73 include/CompilationEngine.hpp
badd +1 templates/writeIfTemplate.txt
badd +1 templates/writeGotoTemplate.txt
badd +5 ~/Documents/courses/nand2tetris/projects/11/Square/Main.vm
badd +10 ~/Documents/courses/nand2tetris/projects/11/Square/Main.jack
badd +23 ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack
badd +7 ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm
badd +1 ~/Documents/courses/nand2tetris/projects/11/Square/Square.jack
badd +1 ~/Documents/courses/nand2tetris/projects/11/Square/Square.vm
argglobal
%argdel
set stal=2
tabnew +setlocal\ bufhidden=wipe
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
exe '1resize ' . ((&lines * 19 + 21) / 42)
exe 'vert 1resize ' . ((&columns * 71 + 106) / 213)
exe '2resize ' . ((&lines * 19 + 21) / 42)
exe 'vert 2resize ' . ((&columns * 71 + 106) / 213)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 213)
exe 'vert 4resize ' . ((&columns * 70 + 106) / 213)
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
let s:l = 64 - ((11 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 64
normal! 0
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp", ":p")) | buffer ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp | else | edit ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/projects/nand2tetris/jack_compiler/include/CompilationEngine.hpp
endif
balt ~/Documents/projects/nand2tetris/jack_compiler/src/SymbolTable.cpp
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
let s:l = 75 - ((0 * winheight(0) + 9) / 19)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 75
normal! 02|
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
let s:l = 1113 - ((0 * winheight(0) + 19) / 39)
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
let s:l = 41 - ((0 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 41
normal! 020|
lcd ~/Documents/courses/nand2tetris/projects/11/ConvertToBin
wincmd w
exe '1resize ' . ((&lines * 19 + 21) / 42)
exe 'vert 1resize ' . ((&columns * 71 + 106) / 213)
exe '2resize ' . ((&lines * 19 + 21) / 42)
exe 'vert 2resize ' . ((&columns * 71 + 106) / 213)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 213)
exe 'vert 4resize ' . ((&columns * 70 + 106) / 213)
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
exe 'vert 1resize ' . ((&columns * 71 + 106) / 213)
exe 'vert 2resize ' . ((&columns * 70 + 106) / 213)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 213)
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
let s:l = 48 - ((2 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 48
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
let s:l = 70 - ((0 * winheight(0) + 19) / 39)
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
let s:l = 57 - ((28 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 57
normal! 015|
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
exe 'vert 1resize ' . ((&columns * 71 + 106) / 213)
exe 'vert 2resize ' . ((&columns * 70 + 106) / 213)
exe 'vert 3resize ' . ((&columns * 70 + 106) / 213)
tabnext
edit ~/Documents/courses/nand2tetris/projects/11/Square/Main.jack
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
2wincmd k
wincmd w
wincmd w
wincmd w
wincmd _ | wincmd |
split
wincmd _ | wincmd |
split
2wincmd k
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
exe '1resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 1resize ' . ((&columns * 105 + 106) / 213)
exe '2resize ' . ((&lines * 13 + 21) / 42)
exe 'vert 2resize ' . ((&columns * 105 + 106) / 213)
exe '3resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 3resize ' . ((&columns * 105 + 106) / 213)
exe '4resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 4resize ' . ((&columns * 107 + 106) / 213)
exe '5resize ' . ((&lines * 13 + 21) / 42)
exe 'vert 5resize ' . ((&columns * 107 + 106) / 213)
exe '6resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 6resize ' . ((&columns * 107 + 106) / 213)
argglobal
balt ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/converttobin_main.vm
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 10 - ((7 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 10
normal! 013|
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack | else | edit ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack
endif
balt ~/Documents/courses/nand2tetris/projects/11/Square/Main.jack
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 23 - ((12 * winheight(0) + 6) / 13)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 23
normal! 0
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/Square/Square.jack", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/Square/Square.jack | else | edit ~/Documents/courses/nand2tetris/projects/11/Square/Square.jack | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/Square/Square.jack
endif
balt ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.jack
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 2 - ((1 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 2
normal! 04|
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/Square/Main.vm", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/Square/Main.vm | else | edit ~/Documents/courses/nand2tetris/projects/11/Square/Main.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/Square/Main.vm
endif
balt ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 5 - ((4 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 5
normal! 016|
lcd ~/Documents/courses/nand2tetris/projects/11/Square
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm | else | edit ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm
endif
balt ~/Documents/courses/nand2tetris/projects/11/Square/Main.vm
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 6) / 13)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 021|
lcd ~/Documents/courses/nand2tetris/projects/11/Square
wincmd w
argglobal
if bufexists(fnamemodify("~/Documents/courses/nand2tetris/projects/11/Square/Square.vm", ":p")) | buffer ~/Documents/courses/nand2tetris/projects/11/Square/Square.vm | else | edit ~/Documents/courses/nand2tetris/projects/11/Square/Square.vm | endif
if &buftype ==# 'terminal'
  silent file ~/Documents/courses/nand2tetris/projects/11/Square/Square.vm
endif
balt ~/Documents/courses/nand2tetris/projects/11/Square/SquareGame.vm
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
silent! normal! zE
let &fdl = &fdl
let s:l = 1 - ((0 * winheight(0) + 6) / 12)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 1
normal! 0
lcd ~/Documents/courses/nand2tetris/projects/11/Square
wincmd w
2wincmd w
exe '1resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 1resize ' . ((&columns * 105 + 106) / 213)
exe '2resize ' . ((&lines * 13 + 21) / 42)
exe 'vert 2resize ' . ((&columns * 105 + 106) / 213)
exe '3resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 3resize ' . ((&columns * 105 + 106) / 213)
exe '4resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 4resize ' . ((&columns * 107 + 106) / 213)
exe '5resize ' . ((&lines * 13 + 21) / 42)
exe 'vert 5resize ' . ((&columns * 107 + 106) / 213)
exe '6resize ' . ((&lines * 12 + 21) / 42)
exe 'vert 6resize ' . ((&columns * 107 + 106) / 213)
tabnext
let s:save_splitbelow = &splitbelow
let s:save_splitright = &splitright
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
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
exe 'vert 1resize ' . ((&columns * 45 + 106) / 213)
exe 'vert 2resize ' . ((&columns * 167 + 106) / 213)
argglobal
enew
file ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation/NvimTree_4
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal nofoldenable
lcd ~/Documents/projects/nand2tetris/jack_compiler
wincmd w
argglobal
enew
setlocal foldmethod=manual
setlocal foldexpr=0
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=0
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
lcd ~/Documents/projects/nand2tetris/jack_compiler/test/files/compilation
wincmd w
exe 'vert 1resize ' . ((&columns * 45 + 106) / 213)
exe 'vert 2resize ' . ((&columns * 167 + 106) / 213)
tabnext 3
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
