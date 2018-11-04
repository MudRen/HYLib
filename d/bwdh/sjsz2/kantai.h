//Cracked by Kafei

int do_watch(string arg);

string look_desk() {
    string msg;
    msg = "���������֯��Ϊ�˴�Ҿ��ˣ��ṩ�˴������⡣\n";
    msg = msg + "������Ŵ���(wan)�Ϳ���(bbq)��\n";
    return msg;
}

int do_get(string arg) {
	 object food, me=this_player();
	 string type;

	 if(!arg) return 0;
	 if(me->is_busy()) return 0;
	 if (sscanf(arg, "%s from desk", type) != 1) return 0;
	 switch (type) {
		  case "wan" : food = new(__DIR__"obj/wan");
							break;
		  case "bbq" : food = new(__DIR__"obj/bbq");
							break;
		  default: write("���Ҳ��� " + type + " ��\n");
					  return 1;
	 }
	 if( food->move(me) )
		  message_vision("$N�Ӽ�����ȡ��һ"+food->query("unit")+food->name()+"��\n", me);
	 else
		  destruct(food);
	 return 1;
}

int do_watch(string arg)
{
	 object camera, me=this_player(), ob;
	 string type;

	 if(!arg) return 0;

	 ob = find_player(arg);
	 if(!ob)
		return notify_fail("�Ҳ��������Ү��\n");

	 if( !ob->query("sjsz/red") && !ob->query("sjsz/white") )
		return notify_fail("����˲���ɽׯ��Ү��\n");

	 camera = query("camera");

	 if( camera && objectp(camera) )
	 {
		destruct(camera);
	 }
	camera = new("/d/bwdh/sjsz/npc/camera");
	camera->move(environment(ob));
	camera->set("target",arg);
	camera->set_leader(ob);
	camera->set("destinations/1", base_name(this_object()) );
	camera->set("destinations/nDest", 1);

	 set("camera",camera);

	 message_vision("$N��ħ��ʦ˵������Ҫ��"+ob->query("name")+"��\n",me);

	 return 1;
}


void init_kantai() {
    object *inv, me=this_player();
    int i;

    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
		if( !objectp(inv[i]) ) continue;
		if( userp(inv[i]) )continue;
        destruct(inv[i]);
    }

	if(me->query("id")=="sheying shi")
	{
		destruct(me);
	}

	 add_action("do_get", "get");
	 add_action("do_watch", "watch");
}

void create_kantai() {
	 set("item_desc", ([
		  "desk" : (: look_desk :),
	 ]));
	 set("no_fight", 1);
	 set("no_steal", 1);
}


