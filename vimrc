set mouse=a
set laststatus=2

" Use Ctrl+Enter to select suggestions in insert mode
inoremap <C-Enter> <C-x><C-o>

" Use Enter to select suggestions or add a new line in insert mode
inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<CR>"


" Set the runtime path for Vundle
set rtp+=~/.vim/bundle/Vundle.vim

" Initialize Vundle
call vundle#begin()

" Add coc.nvim to the list of plugins
Plugin 'neoclide/coc.nvim', {'branch': 'release'}

" Enable coc.nvim
let g:coc_global_extensions = ['coc-clangd', 'coc-python', 'coc-json']

Plugin 'kana/touchui'

" ... Other Vim configurations ...

" End Vundle
call vundle#end()


call plug#begin()
" The default plugin directory will be as follows:
"   - Vim (Linux/macOS): '~/.vim/plugged'
"   - Vim (Windows): '~/vimfiles/plugged'
"   - Neovim (Linux/macOS/Windows): stdpath('data') . '/plugged'
" You can specify a custom plugin directory by passing it as the argument
"   - e.g. `call plug#begin('~/.vim/plugged')`
"   - Avoid using standard Vim directory names like 'plugin'

" Make sure you use single quotes

Plug 'vim-scripts/vimtap'

" On-demand loading
Plug 'preservim/nerdtree', { 'on': 'NERDTreeToggle' }
Plug 'tpope/vim-fireplace', { 'for': 'clojure' }

" Using a non-default branch
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable' }


" Initialize plugin system
" - Automatically executes `filetype plugin indent on` and `syntax enable`.
call plug#end()

set number
set relativenumber
set autoindent
filetype indent on
syntax on
set wildmenu
set wildmode=list:longest
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

" Initialzing plug
call plug#begin('~/.vim/plugged')
Plug 'csexton/trailertrash.vim'
call plug#end()

" Map a key to run Betty style checker
map <F2> :!betty %<CR>

" Map a key to run TrailerTrash
nnoremap <F4> :TrailerTrim<CR>

" Map F3 to select entire buffer and reformat
nnoremap <F3> :%norm! ggVG=<CR>

" Compile via vim
function! Compile()
	let source_filename = expand('%')
	let number = matchstr(source_filename, '\d\+')
	let test_filename = number . '-main.c'
	let output_filename = substitute(source_filename, '\.c$', '', '')
	let command = 'gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c ' . source_filename . ' ' . test_filename . ' -o ' . output_filename
	execute '!'.command
endfunction

command! -nargs=0 Compile :call Compile()

nnoremap <F5> :Compile<CR>
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

" Initialzing plug
call plug#begin('~/.vim/plugged')
Plug 'csexton/trailertrash.vim'
call plug#end()

" Map a key to run Betty style checker
map <F2> :!betty %<CR>

" Map a key to run TrailerTrash
nnoremap <F4> :TrailerTrim<CR>

" Map F3 to select entire buffer and reformat
nnoremap <F3> :%norm! ggVG=<CR>

" Compile via vim
function! Compile()
	let source_filename = expand('%')
	let number = matchstr(source_filename, '\d\+')
	let test_filename = number . '-main.c'
	let output_filename = substitute(source_filename, '\.c$', '', '')
	let command = 'gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c ' . source_filename . ' ' . test_filename . ' -o ' . output_filename
	execute '!'.command
endfunction

command! -nargs=0 Compile :call Compile()

nnoremap <F5> :Compile<CR>
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

" Initialzing plug
call plug#begin('~/.vim/plugged')
Plug 'csexton/trailertrash.vim'
call plug#end()

" Map a key to run Betty style checker
map <C-b> :!betty %<CR>

" Map a key to run TrailerTrash
nnoremap <F4> :TrailerTrim<CR>

" Map F3 to select entire buffer and reformat
nnoremap <F3> :%norm! ggVG=<CR>

" Compile via vim
function! Compile()
	let source_filename = expand('%')
	let number = matchstr(source_filename, '\d\+')
	let test_filename = number . '-main.c'
	let output_filename = substitute(source_filename, '\.c$', '', '')
	let command = 'gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c ' . source_filename . ' ' . test_filename . ' -o ' . output_filename
	execute '!'.command
endfunction

command! -nargs=0 Compile :call Compile()

nnoremap <F5> :Compile<CR>

" Use vim-plug for managing plugins (if you're using Vim-Plug)
call plug#begin('~/.vim/plugged')

" Plugin for Python linting
Plug 'vim-syntastic/syntastic'

call plug#end()

" Enable syntax checking
syntax enable
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

" Map a shortcut key to run the linter
nmap <C-c> :SyntasticCheck<CR>

