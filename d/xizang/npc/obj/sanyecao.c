 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(GRN"��Ҷ��β��"NOR,({"sanyecao"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ���Ѿ����ɵ���Ҷ��β�ݣ�����ɢ���Ų��㣬����������yong�����ˡ�\n");
        set("unit","��");
        set("value", 20000);
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
        diff = this_player()->query("max_qi")-this_player()->query("eff_kee");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
        if(value > diff) value = diff;
            
    message_vision("$N��������Ҷ��β�ݽ��£���������������������\n",this_player());
        this_player()->add("eff_kee",value);
        destruct(this_object());
        return 1;
}  
