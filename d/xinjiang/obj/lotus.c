 // medicine.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"��ɽѩ��"NOR,({"snow lotus"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long",
                "һ���溮�ޱȵģ�����һ�ֵ���ɽѩ����\n");
            set("unit","��");
            set("value", 2000);
        }
       	setup();
} 
void init()
{
  if(this_player()==environment())
        add_action("apply_medicine","yong");
} 
int apply_medicine()
{

        this_player()->set("m_success/��ɽѩ��");
        this_player()->add("score",200);
this_player()->add("qi",800);
this_player()->add("eff_qi",800);
this_player()->add("jing",800);
this_player()->add("eff_jing",800);
        message_vision("$Nһ�ſڣ���һ���溮�ޱȵ���ɽѩ���������ڣ�\n",this_player()); 
        destruct(this_object());
        return 1;
}  
