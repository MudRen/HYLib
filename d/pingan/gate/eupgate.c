inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
��¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ���
������ƽ���ǵ����ģ�����������Ҳ������ϡ�Ŀ���ƽ���㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮�䡣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ewall1",
  "south" : __DIR__"ewall11",
]));
        set("objects", ([
        __DIR__"npc/solider" : 1,
                        ]) );
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}
	  void init() 
{         object me = this_player(); 
               me->query_temp("xunchen");
        if (me->query_temp("xunchen")) me->set_temp("xuncheng/eupgate", 1);
         return;
 } 