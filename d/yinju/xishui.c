inherit ROOM;

void create()
{
  set("short","Ϫˮ");
  set("long",@LONG
����һ��Ϫˮ��ǰ��һƬ��ˮ��ԭ��������ٲ���
��Ȫ��Դͷ
LONG);
  set("outdoors","yinju");
set("objects", ([
    __DIR__"npc/qiaofu": 1,
]));
set("exits",([
   "up"        : __DIR__"fengding",
   "westdown"  : __DIR__"pengquan",
        ]));
  setup();
}
int valid_leave(object me, string dir)
{
  
   if(dir=="up")
    {
       if(objectp(present("qiao fu", environment(me))) && 
(me->query("shen")<0))
            return notify_fail("�Է���ס��˵����ʦ�������ˣ�\n");
    }   
       return ::valid_leave(me, dir);
}