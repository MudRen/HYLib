
//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIR"��"+YEL+"ɳ"+HIR+"��"NOR, ({ "kuangsha dao","dao" }) );
   set_weight(15000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("super",3);
     set("no_save",1);
     set("no_sell",1);
     set("rumor",1);
     set("material", "iron");
     set("value",5000);
     set("long", YEL"�ഫͻ�ʾ���ɳĮ����һ���ط��쳣���ȣ��˴�ʢ��Ѫ��ɫ������ɳ����ɳ�����ɴ���
ɳ�������ɡ����ڹ���ӳ���£�����â˸����ת�����ƾ��������������������������
�����ã����ǲ��ö�˵�������ɴ�־ƾ��һ�ֿ�ɳ����ʹ˵��������£��ѷ���֡�
\n"NOR);
     set("wield_msg", YEL"$N"+YEL+"��������ƽ��ǰ������$n"+YEL+"�����ڰγ�������һ���������ˣ�����ȫ�������졣\n"NOR);
     set("unequip_msg", HIC"$N"+HIC+"˫Ŀ�������Ĺ�â��һգ��գ������$n"+HIC+"���漴�յ����ˡ�\n"NOR);
     set("weapon_prop/dodge",30);
   }
   init_blade(380);
   setup();
}
