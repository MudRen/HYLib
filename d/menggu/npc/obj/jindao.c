#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
   set_name(YEL"��"NOR, ({"jindao", "blade", "dao"}));
   set_weight(5000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "�����ǻƽ�����,������ͷ������һ���ƽ�Ļ�ͷ,����������\n");
     set("value", 5000);
     set("material", "steel");
     set("wield_msg", "$N��$n�������,ֻ����������,�з���������Ѫ��֮ӡ��\n");
     set("unwield_msg", "$N�����е�$n��ػƽ��ʡ�\n");
   }
   init_blade(30);
   setup();
}
