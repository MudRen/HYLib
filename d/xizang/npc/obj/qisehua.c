 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(RED"��ɫ��绨"NOR,({"qisehua"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ���߲ʵ���绨�����˴�˵���ֻ�ֻ�����������ʱ�������ţ�����ʱ����绨\n������߹�Ч�ģ������ã�yong�������� ��\n");
        set("unit","��");
        set("value", 18000);
        }
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{
    int value = 250;
        int diff; 
        if(this_player()->is_fighting())
            return notify_fail("ս���в�����ҩ����\n");
        diff = this_player()->query("max_jing")-this_player()->query("eff_gin");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
        if(value > diff) value = diff;
            
    message_vision("$N��������һ����ɫ��绨�������������ָ�����\n",this_player());
        this_player()->add("eff_gin",value);
        destruct(this_object());
        return 1;
}        
