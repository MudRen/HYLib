#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�鷿");
        set("long", @LONG
������ݹ������鷿�����ںܾ�����������Ӵ����������ֱ�����,
���ڿ�������һ������ܣ���Ȼ����Щ���˳������顣ǽ�ϸ����ż�����
�֡���׳��Ŭ�����ϴ�ͽ�˱�����
LONG);
        set("exits", ([
                "west" : __DIR__"lang5",
        ]));	
	setup();
}
void init()
{
        add_action("do_clean", ({"fan","��","find"}));
}

int do_clean(string arg)
{
     object me,ob; 
     int i;
     i = random(50);
     me=this_player();
     
     if(!arg || arg != "���" ) return 0;

     if (me->query_temp("book_get")){
           message_vision("$NͻȻ�����Լ���ô��ô̰������һ����Ҫ�á�\n", me); 
           return 1;
           }
     if(!me->query_temp("wg_study")){
          message_vision("$N���ַ��˷���\n", me);
          return 1;
          }
   
     if(i < 6){
          message_vision("$N���˵�����������������һ���Լ���Ҫ���顣\n", me);
          switch(random(3)) {
              case 0:  ob=new("/clone/book/parry_book"); break;
              case 1:  ob=new("/clone/book/daodejing-i"); break;
              case 2:  ob=new("/clone/book/laozi1"); break;
              }
          ob->move(me); 
          me->delete_temp("wg_study");
          me->set_temp("book_get",1);
          }
     else message_vision("$N���˰���û�����Լ���Ҫ�ġ�\n", me);
     me->receive_damage("jing", random(5));
     return 1;
}
