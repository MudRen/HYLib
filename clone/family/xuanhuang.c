// xuanhuang.c �������嵤

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "�������嵤" NOR, ({ "xuanhuang dan", "dan" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����з��Ƶľ����浤���������񻰰�Ĺ�Ч��"
                            "�������������������ҩ��\n");
                set("value", 250000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        int effect;
        int neili;

        effect = 0;
        message_vision(HIW "$N" HIW "һ������������һ��" +
                       this_object()->name() + HIW "��ֻ��$N"
                       HIW "����һ�������϶�ð����������\n" NOR, me);
        if (me->query("gift/xuanhuang") <= 200 && ! me->query("jieti"))
        {                        
                message_vision("ֻ��$N" HIW "����һ�������϶�ð����������\n", me);
                if (! me->query("jieti"))
                me->add("combat_exp", 150000);
                me->improve_skill("force", 250000);
                me->improve_skill("parry", 250000);
                me->improve_skill("dodge", 250000);
        }
        neili = me->query("max_neili") + 500;
        if (neili > me->query_neili_limit())
                neili = me->query_neili_limit();
        me->set("max_neili", neili);
        me->add("gift/xuanhuang", 1);
        destruct(this_object());
        return 1;
}
int query_autoload() { return 1; }  

