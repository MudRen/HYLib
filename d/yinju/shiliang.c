inherit ROOM;

void create()
{
  set("short","ʯ��");
  set("long",@LONG
ɽ���Ӵ˶Ͽ����м���ͻ����ʯ���������и�����
��������ʯ��֮�ϣ��������Ҫ�������ͱ�������
��ͬ�⣡
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/shusheng": 1,
]));
set("exits",([
   "west"  : __DIR__"shimiao",
  "east"  : __DIR__"shanlu",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="west")
    {
       if(objectp(present("zhu ziliu", environment(me))) && 
(me->query_temp("answer_shusheng")!=1))
            return notify_fail("������ס��˵����ʦ�������ˣ�\n");
    }   
       return ::valid_leave(me, dir);
}
