//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
        set_name(HIG"����ʩ����"NOR, ({ "yueye spear","yueye","spear" }) );
        set_weight(50000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 50000);
     set("super",5);
        set("rumor",1);
        set("material", "iron");
        set("long",HIG "��ìԭ��ͻ������������У��ؾ�ʮ�Žì��������ʩ���ǡ�����ͻ�ʹ���⼴��ҹ֮�ǣ�
��������ʱ��֮��������ݺ��ԭ���޵��֣�������֮���ѱ���Ϊ��û�����ܰ���������
����������ʮ�����ì���á���ì��֮����Ӳ�����Ⲣ����������֮����������ʹ�����磬��
����������ȷʵ����������
\n"NOR);
        set("wield_msg", HIW"$N"+HIW+"�������ԣ���ֹ��ˮ���ӱ�����Ȼ�������ì���η紵���裬����ΡȻ������\n"NOR);
        set("unequip_msg", HIG"$N"+HIG+"�����ת���������������𣬾�����ô������������е�$n��\n"NOR);
   }
   init_club(800);
   setup();
}

int hit_ob(object me,object target)
{
   if(random(10)+random(10)>10){
    message_vision("$N���е�"+this_object()->name()+"����һ��������$n������Ϣһ��!\n",me,target);
if (userp(target))
{
	 target->add("neili",-target->query("neili")/10);
}
else
{
	 target->add("neili",-random(288));
}

    return 1;}
    return 1;
}
