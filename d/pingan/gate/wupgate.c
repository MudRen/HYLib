inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
������ƽ���ǵ����ģ�����������Ҳ������ϡ�Ŀ���ƽ���㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wwall1",
  "south" : __DIR__"wwall10",
  "down" : "d/pingan/pinganmen",
]));
        set("objects", ([
        __DIR__"npc/solider4" : 1,
                        ]) );
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}
	  void init() 
{         object me = this_player(); 
               me->query_temp("xunchen");
        if (me->query_temp("xunchen")) me->set_temp("xuncheng/wupgate", 1);
         return;
 } 

