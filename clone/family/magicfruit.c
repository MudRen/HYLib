// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "ħ����Ĺ�" NOR, ({ "magic fruit", "magic", "fruit" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ͬʱ��������ħ��ͷ��Ĺ�ʵ����֪�����˻���ʲôЧ����\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);

        if (me->query("gift/int/fail"))
        {
                me->add("gift/int/fail", -1);
                if (me->query("gift/int/all"))
                {
                        me->add("gift/int/all", -1);
                        if (me->query("gift/int/all") < 1)
                                me->delete("gift/int/all");
                }
                else
                        me->add("gift/xiandan", -1);
                if (me->query("gift/int/fail") < 1)
                        me->delete("gift/int/fail");
        } else
        if (me->query("gift/str/fail"))
        {
                me->add("gift/str/fail", -1);
                if (me->query("gift/str/all"))
                {
                        me->add("gift/str/all", -1);
                        if (me->query("gift/str/all") < 1)
                                me->delete("gift/str/all");
                }
                else
                        me->add("gift/shenliwan", -1);                
                if (me->query("gift/str/fail") < 1)
                        me->delete("gift/str/fail");
        } else
        if (me->query("gift/con/fail"))
        {
                me->add("gift/con/fail", -1);
                if (me->query("gift/con/all"))
                {
                        me->add("gift/con/all", -1);
                        if (me->query("gift/con/all") < 1)
                                me->delete("gift/con/all");
                }
                else
                        me->add("gift/xisuidan", -1);                
                if (me->query("gift/con/fail") < 1)
                        me->delete("gift/con/fail");
        } else  
        if (me->query("gift/dex/fail"))
        {
                me->add("gift/dex/fail", -1);
                if (me->query("gift/dex/all"))
                {
                        me->add("gift/dex/all", -1);
                        if (me->query("gift/dex/all") < 1)
                                me->delete("gift/dex/all");
                }
                else
                        me->add("gift/unknowdan", -1);
                if (me->query("gift/dex/fail") < 1)
                        me->delete("gift/dex/fail");
        } 
        
        tell_object(me, HIG "һ�ɻ�����Ȼ��ȫ������"
                            "��ȫ�����ѣ�ǡ�ڴ�ʱһ����̹֮��"
                            "��Ȼ���𣬶ٸ�ȫ��������ˡ�\n" NOR);

        destruct(this_object());
        return 1;
}


