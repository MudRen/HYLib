// sheku.c
// �߿�
inherit ROOM;
void create()
{
	set("short","�߿�");
	set("long",@long
�������궾���������ȳ��˱ǣ���ض����ִ��ֳ��Ķ��ߺ�һ�ѶѰ׹ǣ�
ʱ���з��񱻶���Ѭ�裬��������Ϊ���ߵ���ʳ��Ⱥ��֮��Ļ�������Ҳ��
�ҳ��㷹��ֻ����Щ�书��ǿ���ö����ֲ��ܴ��������롣�˴�����û��ʲ
ô��·������Ե�������(go)����
long);
	/*set("exits",([
	    "northwest" : __DIR__"treen2",
          "southwest" : __DIR__"trees2",
          "east" : __DIR__"sande",
]));*/
set("objects",([
__DIR__"npc/shenlong": 1,
__DIR__"npc/dushe2" : 4,
]));
	set("outdoors", "������");
        setup();
}
	    	
void init()
{
     object me;

     me=this_player();
     if((int)me->query_skill("poison",1)<100)
     {
         me->apply_condition("snake_poison_poison", (5-((int)me->query_skill("poison",1))/20)*10);  
     }       
     add_action("do_go", "go");
     add_action("do_bo", "bo");
}

int do_bo(string arg)
{
     object me;
     object bg;
     object she;
     object * ob;
     int i,j;

     me = this_player();
       
     if(!living(me) ) return 0;
     if (me->is_busy() || me->is_fighting())
     	return 0;

if (!present("shenlong", this_object()))
return notify_fail("����ʲôҲû�а�!\n");
     if(!arg || arg!="�׹�")
	return 0;
     if(random(10)<2)
     {
	if(objectp(bg=new(__DIR__"npc/obj/baogou")))
	{
		tell_room(this_object(),"��Ȼ��ʲô������һ�Ѱ׹��е��˳�����\n");
		bg->move(this_object());
	}
     }
     else if(random(10)>6)
     {
	ob = all_inventory(this_object());
	j=0;
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query("id")=="shenlong")
			j=j+1;
	}
	if(j>=5)
		return 0;
	tell_room(this_object(),"ͻȻ�Ӱ׹�����ܳ�һ���ȸղŸ��Ӵֵľ��ߣ�\n");
	she=new(__DIR__"npc/shenlong");
	she->set("combat_exp", 500000+random(3000001));
	set("max_qi",26000+random(4001));
        set("max_jing",26000+random(4001));

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 800+random(501));
	set_temp("apply/damage", 480+random(21));
	set_temp("apply/armor", 800+random(501));
 	she->move(this_object());
    }
    else
	return 0;
    return 1;
}

int do_go(string arg)
{
     object me;

     me = this_player();
       
     if(!living(me) ) return 0;
     if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

     if( !arg || arg == "" || (arg != "west" && arg != "east" && arg != "north" && arg != "south" ))
        return notify_fail("��Ҫ������ȥ��\n");
     if(random(10)>=5)
         me->move(__DIR__"treen1");
     return 1;
}
