// mg-room4.c �Թ�����

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�Թ�����" NOR);
        set("long", @LONG
������һ����ã��ıڹ��ļ��з������к��ˡ�����д���ֶ�
�Ǻ��֣�ͨ���ϻ������˹��е������þߣ�ȴ�����������˵����£�
�������֮�������������������˽�����
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "southwest" : __DIR__"mg-room1",
              "northwest" : __DIR__"mg-room5",                     
        ]));
        setup(); 
        set("stone_count", 2);
}

void init()
{
   object me;
   me = this_player();    
   if(random(10) > 6  && query("stone_count") >= 1)
      {
      message_vision("ͻȻ�����һ�裬����ȵ���ʲôӲ������\n", me);
      new(__DIR__"obj/shiqi")->move(environment(me));
      add("stone_count", -1);
      }
}
int count = 1;
void reset()
{
    if (--count == 0) {count = 10; set("tu_count", 2); ::reset();}
}
int clean_up()
{
       return 0;

}