 // medicine.c
inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(WHT"ѩ֥"NOR,({ "xuezhi"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ�����ʥĸѩ���ѩ֥��ѩ����Ͼ���������棬 �����ã�yong�������� ��\n");
        set("unit","��");
        set("value", 15000);
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
        diff = this_player()->query("max_jing")-this_player()->query("eff_sen");
        if(!(diff))    return notify_fail("��û�����ˣ�\n");
        if(value > diff) value = diff;
            
    message_vision("$N��������ѩ֥������о�ƽ������ࡣ\n",this_player());
        this_player()->add("eff_sen",value);
        destruct(this_object());
        return 1;
}     
