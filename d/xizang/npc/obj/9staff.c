#include <ansi.h>
#include <weapon.h> 
inherit STAFF; 
void create()
{
        set_name("�Ż�����" , ({ "9-ring staff", "staff" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���ִ��ֳ��ĺ������ȣ��������žŸ����������м仹����Щ�ܲ����۵Ĳ��ġ�\n");
                set("value", 6200);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ���ںڵ�$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        } 
        set("skill", ([
                        "name":         "iron-cloth",             
                        "exp_required": 50000,                          
                        "sen_cost":     50,                     
                        "difficulty":   50,                     
                        "max_skill":    50              
                        ]) );
        ::init_staff(120);
}  
