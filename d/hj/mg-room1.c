// mg-room1.c �Թ�����
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�Թ�����" NOR);
        set("long", @LONG
���������಻�ϵ���һ�з��ᡣÿһ�䷿�д󶼹��з���żȻ��
���ϼ����������ģ�д���ǡ��߲���������������̩�������������ʮ
���꡹�ȵ����������������������˽�����
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "south" : __DIR__"tianjin",
              "north" : __DIR__"mg-room2", 
              "northwest" : __DIR__"mg-room3",    
              "northeast" : __DIR__"mg-room4",               
        ]));
        setup(); 
        set("tu_count", 2);
}

void init()
{
   object me;
   me = this_player();    
   if(random(10) > 7  && query("tu_count") >= 1){
      message_vision("ͻȻһ��΢�紵�������һ��ͼ��Ʈ���ڵء�\n", me);
      new(__DIR__"obj/tu")->move(environment(me));
      add("tu_count", -1);
      }
}
int count = 1;
void reset()
{
    if (--count == 0) {count = 20; set("tu_count", 2); ::reset();}
}
int clean_up()
{
       return 0;

} 
