inherit ROOM;

void create()
{
  set("short","ɽ��");
  set("long",@LONG
�����Ƕ��͵�ɽ�¡��˴�ɽ�ƶ��ͣ���ɽ����һ����
С�ĺ����ױ����鵽�¹�֮�С�
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/nongfu": 1,
__DIR__"npc/niu": 1,
]));
set("exits",([
   "west"  : __DIR__"shanlu",
   "east"  : __DIR__"pingdi",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="west")
    {
       if(objectp(present("wu santong", environment(me))) && 
(me->query_temp("help_nongfu")!=1))
            return notify_fail("ũ����ס��˵����ʦ�������ˣ�\n");
    }   
       return ::valid_leave(me, dir);
}



