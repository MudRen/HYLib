// ������ ctrl.c
// By River 99/04/15
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"����̨"NOR);
        set("long", @LONG
�������齣��ӱ�������ʦ�����ң����ܿ����ڶ���ʦ����ææ���ڸ�Щ
ʲô�����������һ�źܴ�Ŀ���̨�������ʾ��һ�Ű�ť����Ϊ���Ե���һ
����ɫ�İ�ť��anniu)����֪������ȥ��ʲô�����
LONG
        );

        set("exits", ([
                "down" : "/d/wizard/wizard_meet",
        ]));

        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_push", "an");
}

void check_trigger()
{
       object room;
       object thisroom = this_object();
       if(!(room = find_object(__DIR__"xiuxishi2")))
             room = load_object(__DIR__"xiuxishi2");
       if( room = find_object(__DIR__"xiuxishi2")){
         if( !room->query("exits/enter")){
                 room->set("exits/enter", __DIR__"gate");                 
                 message("vision", HIR"ֻ������Ȼһ�����Խ�ɽׯ����Ϣ�ҵĴ��ű����ˡ�\n"NOR, thisroom);
                 message("vision", HIW"ֻ������֨һ������Ϣ�ҵĴ��ű����ˣ������ͨ���Խ�ɽׯ�ˡ�\n"NOR, room);
                 remove_call_out("close");
                 call_out("close", 100); 
                 }
                else message("vision", HIW"�Խ�ɽׯ����Ϣ�ҵĴ����Ѿ������ˣ��ٰ�Ҳû�����ˡ�\n"NOR, thisroom);
           } 
          else message("vision", "ERROR: Room 2 not found\n", thisroom);          
}

void check_trigger1()
{
       object room1;
       object thisroom = this_object();
       if(!(room1 = find_object(__DIR__"xiuxishi1")))
             room1 = load_object(__DIR__"xiuxishi1");
       if( room1 = find_object(__DIR__"xiuxishi1")){
         if( !room1->query("exits/enter")){                 
                 room1->set("exits/enter",__DIR__"houting");
                 message("vision", HIR"ֻ������Ȼһ�����Խ�ɽׯ����Ϣ�ҵĴ��ű����ˡ�\n"NOR, thisroom);
                 message("vision", HIW"ֻ������֨һ������Ϣ�ҵĴ��ű����ˣ������ͨ���Խ�ɽׯ�ˡ�\n"NOR, room1);
                 remove_call_out("close1");
                 call_out("close1", 100); 
                 }
                else message("vision", HIW"�Խ�ɽׯ����Ϣ�ҵĴ����Ѿ������ˣ��ٰ�Ҳû�����ˡ�\n"NOR, thisroom);
           } 
          else message("vision", "ERROR: Room 1 not found\n", thisroom);          
}

void close()
{
        object room;
        if( room = find_object(__DIR__"xiuxishi2"))
        room->delete("exits/enter");        
        message("vision", HIW"ֻ������֨һ������Ϣ�ҵĴ����ֱ������ˡ�\n"NOR, room);
}

void close1()
{
        object room1;
        if( room1 = find_object(__DIR__"xiuxishi1"))
        room1->delete("exits/enter");
        message("vision", HIW"ֻ������֨һ������Ϣ�ҵĴ����ֱ������ˡ�\n"NOR, room1);
}

int do_push(string arg)
{
       object me;
       me = this_player();       
       if (userp(me) && !wiz_level(me))
          return notify_fail("�㲻����ʦ����Ҫ����Ҷ�����������ⲻ��Ŷ��\n");
       if (!arg || arg !="anniu")
          return notify_fail("��Ҫ��ʲô��\n");
       if (arg == "anniu"){
           message_vision(HIR"$N�������˿���������ʳָ�����ذ����˰�ť��\n"NOR, me);
           check_trigger();
           check_trigger1();
           return 1;
           } 
          return notify_fail("��Ҫ��ʲô��\n");
}
