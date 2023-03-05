# Prerequisites:
# 1. Create your own layout in tmux and save it with tmux-resurrect
# 2. tmux, tmux-resurrect
# 3. vscode
# 4. Optional monitors: iotop, lm-sensors, bmon

# Create the session, then restore the layout (I created this manually)
tmux new-session -t srv -d
~/plugins-n-stuff/tmux-resurrect/scripts/restore.sh
tmux set-option window-size manual

# Start all processes
tmux send-keys -t srv:0.0 "code tunnel --accept-server-license-terms" Enter
# Pane #1 runs top. tmux-resurrect supports automatically resuming the top process.
tmux send-keys -t srv:0.2 "sudo iotop -o -d 0.5" Enter
tmux send-keys -t srv:0.3 "watch -n 0.5 sensors" Enter
tmux send-keys -t srv:0.4 "bmon -p '!lo' -r 0.5 -R 0.5" Enter

# Set up some more configuration options for bmon (there are no command line arguments for this)
tmux send-keys -t srv:0.4 "d i"

# Set up the environment for VS Code
tmux select-window -t srv:1
tmux select-pane -t srv:1.0
tmux send-keys -t srv:1:0 "zsh" Enter
tmux attach-session -t srv
