inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�Ϸ���ƽ���ǵ����ģ�����������Ҳ������ϡ�Ŀ���ƽ���㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nwall1",
  "east" : __DIR__"nwall11",
]));
        set("objects", ([
        __DIR__"npc/solider2" : 1,
                        ]) );
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}

	  void init() 
{ 
        object me = this_player(); 
               me->query_temp("xunchen");
        if (me->query_temp("xunchen")) me->set_temp("xuncheng/nupgate", 1);
         return;
 } 
