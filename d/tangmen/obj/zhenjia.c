//kaolu.c
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������ϻ", ({ "anqi baoxia" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
set("no_clone",1);
            set("unit", "��");
            set("value", 15000);
            set("material", "stone");
            set("long", "һ��������ϻ���������װ���õİ������������������(insert)������\n");
          }

    setup();
}
void init()
{
 add_action("do_kao","insert");
 add_action("do_kao","zhuang");
}                             

int do_kao(string arg)
{
        object me;
        object tar;
        object meat;
        string name;
        int decayed;
        me = this_player();
        if( !arg || arg == "")
                return notify_fail("��װʲô��\n");

	if( me->is_busy() )
	return notify_fail("( ����һ��������û����ɡ�)\n");

        if(!objectp(tar = present(arg, me)) )
                         return notify_fail("��װʲô��\n");
         if(!objectp(tar = present(arg, me)) )
                return notify_fail("��װʲô�ϰ���\n");
        if(tar->is_character() && living(tar))//!tar->is_corpse())
                return notify_fail("�Ǹ�����װ�\n");
        if( (string)tar->query("skill_type") != "throwing")
                return notify_fail("�Ǹ�����װ�ֻ�ܸ��������䣮\n");
        if( tar->query_amount() >= 100)
                return notify_fail("���ڲ���Ҫ���������䣮\n");

        if( tar->query("skill_type")== "throwing")
        {
          tar->add_amount(100);
            }
        message_vision("$N�򿪰�����ϻȡ����һЩ$n���������С�\n", me, tar);
        me->start_busy(3);

        return 1;
}
