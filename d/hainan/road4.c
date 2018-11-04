// Room: /d/hainan/road4
inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG
���͵�ɽ·,�����ط��Ǵ���ʯ�����˶�,���������������Ѷ���. 
�����ǲ�ã�ĺ�����.�ڹ�������,ʲô��������. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 2,
]));
  set("outdoors", "/d/hainan");
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"road2",
  "east" : __DIR__"pubu",
]));

  setup();
}

int valid_leave(object me,string dir)
{
        string fam;
        object npc;

        fam=(string)me->query("family/family_name");
	npc=present("nv dizi",environment(me));
	if( fam && fam!="������" && objectp(npc) &&
		dir=="east")
	return notify_fail(npc->query("name")+"˵�����Ǳ��ɵ��ӽ�ֹ���¡�\n");
        return ::valid_leave(me,dir);
}

