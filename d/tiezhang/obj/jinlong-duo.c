#include <weapon.h>
#include <ansi.h>

inherit HAMMER;
void create()
{
        set_name(HIY"������"NOR,({ "jinlong duo", "duo","hammer" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "��");
                set("value", 70);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 5);    
                set("material", "steal");
                set("treasure",1);
                set("wield_maxneili", 80);
                set("wield_str", 30);
		set("long", HIY"����һ�ѽ����ε��Ϲ���ᣬ����������ֻ�����������������ܣ������������ڣ�
ѣ����Ŀ��������ʹ��֮�˵�����Ҳ�������С�"NOR);
                set("wield_msg",HIY"$N˫�����ⶸ�䣬����һ̽��һ��ѣ������ͨ��ɢ���Ų�����ɫ��ԵĽ����ᣬ�Ѿ��������С�\n"NOR);             
                set("unwield_msg", HIY "$N���н��һ������������ʧ��$N�Ļ��С�\n"NOR);  
        }
        init_hammer(500);
        setup();
}
