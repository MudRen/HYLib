inherit ROOM;

void create()
{
  set("short","ʯ��");
  set("long",@LONG
����һ��ɾ���ʯ�ң�����ʮ�ּ�ª����ǽ����һ��Сľ����
���¼������ţ��������������棬�۾�΢�գ�����˯ȥһ�㡣
LONG);
 
set("objects", ([
    __DIR__"npc/yideng": 1,
  __DIR__"npc/sengren": 1,
]));
set("exits",([
   "west"  : __DIR__"zhulin",
  
        ]));
  setup();
replace_program(ROOM);
}