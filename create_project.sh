if [[ -z "$1" ]]; then
    echo "Must specify a folder name"
    exit 1
fi

# cloned git repos are still a copy of the original owner
# and makes it difficult to add to other git repos so
# we just delete the .git folder to make it easier to commit a project folder
git clone https://github.com/Xetera/CPPTemplate.git "$1" && rm -rf "$1/.git"
