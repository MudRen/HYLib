// Room: /d/feitian/jiedao3.c
inherit ROOM;

#include <ansi.h>  
void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG
�ֵ��·���һ���������õĴ�ׯ��������˳�����Ϊ���˴壬�Լ���Ϊ���ˡ�
���Ϸ��߾͵��������ˡ�������һ���Թ�һ����С·��ͨ�����֡�
LONG);

  set("outdoors", "feitian");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"shulin",
  "west" : __DIR__"jiedao2",
  "south" : __DIR__"luorencun",
]));

  setup();
//  replace_program(ROOM);
}
void init()
{
    add_action("do_enter", "enter");
}

int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="midao" ) 
       {
         tell_object(this_player() , "��Ҫȥ�Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "����������")
{
     message_vision("$N���Ƿ������������ܵ�,�㲻��ʶ·!\n",  ob);
    return 1;
}
    if(!ob->query_temp("shirenok"))
{
     message_vision("$N����ȥ̽һ�������е������!!\n",  ob);
    return 1;
}

    ob->move("/d/feitian/pubu") ;
    tell_object(ob, BLU "�㿴����С·��ֱ���߳�������!\n" NOR ) ;
    return 1 ;
}