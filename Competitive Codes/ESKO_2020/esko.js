process.stdin.resume();
process.stdin.setEncoding('utf8');
var stdin_input = "";

process.stdin.on("data", function (input) {
    stdin_input += input;                               
    // Reading input from STDIN
});

process.stdin.on("end", function () {
   main(stdin_input);
});



class graph{
    constructor(){
        this.AdjList = new Map();
        this.mp  = {};
        this.rmp = {};
        this.mp_pro = [];
        this.result = [];
        this.flag = false;
    }
    calc_result(startingNode){
        this.result.sort((a,b)=>{
            return b[0]<a[0];
        });
        if(this.result[0][0]!==0){
            this.flag = true;
            var reso = "1";
            reso += startingNode;
            for(var i in this.result){
                reso += " = ";
                reso += this.result[i][0];
                reso += this.result[i][1];
            }
            console.log(reso);
        }
    }
    dochange(total_nodes){
        this.result=[];
        for(var i=0;i<total_nodes;i++){
            this.mp_pro[i] = 1;
        }
    }
    addVertex(vertex){
         this.AdjList.set(vertex, []);
    }
    addEdge(vertex, node, weight){
        this.AdjList.get(vertex).push({
            "dest":node,
            "weight":Number(weight),
            "reverse":false
        });
        this.AdjList.get(node).push({
            "dest":vertex,
            "weight":Number(weight),
            "reverse":true
        });
    }
    printGraph(){
        var get_keys = this.AdjList.keys();  
        for (var i of get_keys) { 
            var get_values = this.AdjList.get(i); 
            var conc = ""; 
            for (var j of get_values)
                console.log(j);
            console.log(i + " -> " + conc); 
        } 
    }
    mapper(point){
        for(var i=0;i<point.length;i++){
            this.mp[point[i]] = i;//["pallet"]=>0
            this.rmp[i] = point[i];//0=>"pallet"
        }
    }
    dfs(s,visited){
        visited[this.mp[s]] = true;
        var getNeighbors = this.AdjList.get(s);
        for(var i in getNeighbors){
            var get_dest_node = getNeighbors[i];
            if(!visited[this.mp[get_dest_node.dest]]){
                //calculation
                if(get_dest_node.reverse){
                    this.mp_pro[this.mp[get_dest_node.dest]] = this.mp_pro[this.mp[s]] /  get_dest_node.weight;
                    if(this.mp_pro[this.mp[get_dest_node.dest]]<1)
                        this.mp_pro[this.mp[get_dest_node.dest]] = 0;
                }else{
                    this.mp_pro[this.mp[get_dest_node.dest]] = this.mp_pro[this.mp[s]] *  get_dest_node.weight;
                }
                this.result.push([this.mp_pro[this.mp[get_dest_node.dest]],get_dest_node.dest]);
                this.dfs(get_dest_node.dest,visited);
            }
        }
    }
}


function main(input){
    var data = input.split('\n');
    const n = data.length;
    const point = data[0].split(';');
    node = new graph();
    for(var ii=0;ii< point.length;ii++){
        node.addVertex(point[ii]);
    }
    var decre = n-1;
    var k = 1;
    while(decre--){
        var ss = data[k].split(' ');k++;
        node.addEdge(ss[0],ss[3],ss[2]);
    }
    
    node.mapper(point);
    for(var ki=0;ki<n;ki++){
        if(node.flag) break;
        var visited = [];
        for(var ui=0;ui<n;ui++) visited[ui] = false;
        node.dochange(n);
        var startingNode = point[ki];
        node.dfs(startingNode,visited);
        node.calc_result(startingNode);
    }
}