bool Graph::isConnected(){
    bool visited[V];
    int i;
    for(i=0;i<V;i++)
        visited[V]=false;
    for(i=0;i<V;i++){
        if(adj[i].size()!=0) break;
    }
    if(i==V) return true;
    DFSUtil(0,visited);
    for(i=0;i<V;i++){
        if(visited[i]==false and adj[i].size() > 0) 
            return false;
    }
    return true; 
}

int Graph::isEulerian(){
    if(isConnected()==false) return 0;    
    int odd=0;
    for(int i=0;i<V;i++){
        if(adj[i].size()%2!=0) odd++;
    }
    if(odd > 2) return 0;
    else if(odd == 0) return 2;
    return 1;
}


