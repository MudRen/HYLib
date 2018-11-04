// Room: /d/city/pinganmen
inherit ROOM;

void create ()
{
  set ("short", "ƽ����");
  set ("long", @LONG
������칬ƽ���ǵ���ڣ��������޵�ׯ�ϡ��Ӵ˴����У��͵�ƽ����
�ˡ�һ��ƽ���ǣ���Զ����ƽ��������Ѫ�ȷ��꣬��һ�������ľ���ȥ����
��������У���ͽ��뽭���ˡ�
LONG);

  set("outdoors", "pingan");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"west3",
   "up" : __DIR__"gate/wupgate",   
  "down" : "/d/city/guangchang",
]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
set("no_npc",1);
  setup();
}

int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if (  me->query_temp("xunchen")< 1 && dir == "up" )
        return notify_fail("ʿ��˵������һ��,���������˵һ��,����Ѳ�ǣ�\n");
	if (dir =="east")
	{
		if ( me->query("PKS") >= 10)
		return notify_fail("��ɱ��̫�����ң�ƽ���ǲ���ӭ�㣡\n");
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
