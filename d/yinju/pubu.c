inherit ROOM;

void create()
{
  set("short","���ٲ�");
  set("long",@LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵�
�ٲ������ٲ���pubu��һйǧ������ġ�
LONG);
  set("outdoors","yinju");
  set("objects", ([
    __DIR__"npc/yuren": 1,
]));
set("item_desc", ([
                "pubu" : "���ٲ�������������ζ�����ȥ׽��zhuo)��\n",
]));

  set("exits",([
   "eastup"  : __DIR__"tiezhou",
   "westdown"  : __DIR__"doulu",
        ]));

  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="eastup")
    {
       if(objectp(present("diancang yuyin", environment(me))) && 
(me->query_temp("give_wawa")!=1))
            return notify_fail("������ס��˵����ʦ�������ˣ�\n");
    }   
       return ::valid_leave(me, dir);
}void init()
{
        add_action("do_zhuo","zhuo");
}
int do_zhuo(string arg)
{
       object ob;
        object me = this_player();

	if (arg != "pubu")
		return 0;
if (me->query("dex")>20)
{
	message_vision("$N�����״��ٲ���׽����һ�������ޡ�\n", me);
           ob=new("/d/yinju/npc/obj/wawayu");
           ob->move(me);
           me->add("jing",-30);
}
else 
message_vision("$N�����׿���һ��������,�����������ֲ������ݸ������ˡ�\n", me);
return 1;
}