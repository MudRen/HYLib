// mg-room1.c �Թ�����
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�Թ�����" NOR);
        set("long", @LONG
������һ����ã��ıڹ��ļ��з������к��ˡ�����д���ֶ�
�Ǻ��֣�ֻ����빬����Ȼ���ݣ����ж����˻�ɳ�����Ż�Ҳ�ж���
�ģ��������֮�������������������˽�����
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "southeast" : __DIR__"mg-room4", 
              "southwest" : __DIR__"mg-room3",                      
        ]));     
        setup(); 
        set("tu_count", 2);
}
int count = 1;
void reset()
{
    if (--count == 0) {count = 20; set("tu_count", 2); ::reset();}
}

void init()
{
   object me;
   me = this_player();
    
   if(random(10) > 6  && query("tu_count") >= 1){
      message_vision("ͻȻһ��΢�紵�������һ��ͼ��Ʈ���ڵء�\n", me);
      new(__DIR__"obj/tu")->move(environment(me));
      add("tu_count", -1);
      }
}
int clean_up()
{
       return 0;

} 
