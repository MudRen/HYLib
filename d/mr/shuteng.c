// /u/beyond/mr/shuteng.c
// this is made by beyond
// update 1997.7.2
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",GRN"����"NOR);
         set("long",@long
���ﳤ�������٣�һ֦һ֦������(teng)��ס�����⣬�����̸����,��
ֻ�����������������¡�
long);
         set("item_desc",([
         "teng" : "������ס�����⣬����û��һ����ߣ�ʹ�㼫���Ĳ�����֦(zhi)��\n",
         "zhi" : "���ٵ�֦���Ϻ������˵���ָ���ȥ�ĺۼ���\n",
         ]));
         setup();
}           
 void init()
 {
        add_action("do_move", "pa");
        add_action("do_move", "move");
        add_action("do_leave", "leave");
        add_action("do_leave", "down");                                   
        add_action("do_bo", "bo");    
add_action("do_insert","insert");
add_action("do_insert","cha");
 }                                    
 int do_move(string arg)
{
        object me = this_player();
        if (arg !="down")
        return notify_fail("��Ҫ����������\n");
        if (arg == "down")
        message_vision("$NС�ĵ���ס���٣�������ȥ��\n" , me);
        me->move(__DIR__"hhyuan");
        return 1; 
}                                     
int do_leave(string arg)
{
        object me;
        me = this_player();
        message_vision(HIR "$N�ɿ�˫�֣�����������������׹ȥ�����߷���������\n" NOR, me);
        me->move(__DIR__"hhyuan");
        me->unconcious();
        return 1;
}                                
int do_bo(string arg)
{
        object me;
        me = this_player();
        if (arg !="teng")
        return notify_fail("��Ҫ��ʲô��\n");
        if (arg =="teng")
        message_vision(
		"$N�������٣���ǿ¶��һ˿���⣬��ʱ�㿴��һƬʢ����ӣ�һ���\n",
	me);
        return 1;
}
int do_insert(string arg)
{
	object me;
	me = this_player();
if ( !living(this_player()) || arg != "shuteng" )
        	return 0;
        if (me->query("family/family_name")!="����Ľ��")
	        return 0;
        if ((int)me->query_skill("finger", 1) >101 )
        return notify_fail("�����ֲ�����٣������Ѿ��޷������Ļ���ָ���ˣ�\n");
        if ( (int)me->query("jing")<30) {
                me->receive_damage("jing", 10);
                write("��̫���ˣ��Ѿ�û��������������������ˣ�\n");
                message_vision(HIR "$N̫����û��������ס���٣�����������������׹ȥ�����߷�����������......\n" NOR, me);
                me->move(__DIR__"hhyuan"); 
                message_vision(HIR"$N�������ϵ��������������˵��ϡ�\n" NOR, me);
       		me->unconcious();              
	        return 1;
	}
me->receive_damage("jing", random(15)+15);
        write("�㲻ʱ������ָ������٣����������Щ��΢�Ĵ��ˡ�\n");
        message_vision("$N���ڲ�ʱ������ָ������١�\n", me);  
	me->improve_skill("finger", me->query("int"));       
	return 1;
}
