inherit ROOM;
void create()
{
        set("short", "�ϳ���¥");
        set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
������ƽ���ǵ����ģ�����������Ҳ������ϡ�Ŀ���ƽ���㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swall1",
  "west" : __DIR__"swall11",
]));
        set("objects", ([
        __DIR__"npc/solider3" : 1,
                        ]) );
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}
	  void init() 
{         object me = this_player(); 
               me->query_temp("xunchen");
        if (me->query_temp("xunchen")) me->set_temp("xuncheng/supgate", 1);
         return;
 } 
