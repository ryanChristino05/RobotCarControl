server.on("/distances", []()
          {
  String json = "{\"gauche\": " + String(distanceGauche) + ", \"droite\": " + String(distanceDroite) + "}";
  server.send(200, "application/json", json); });

useEffect(() = > {
    const interval = setInterval(() = > {
        fetch('http://192.168.84.63/distances')
            .then(res = > res.json())
            .then(data = > {
                setDistances(data); // par exemple : { gauche: 25, droite: 18 }
            })
            .catch(() = > setDistances({gauche : 0, droite : 0}));
    },
 3000);

    return () = > clearInterval(interval);
},
          []);

<Text style={{ color: colors.text }}>
  Distance Gauche : {distances.gauche} cm
</Text>
<Text style={{ color: colors.text }}>
  Distance Droite : {distances.droite} cm
</Text>
