// ������
// diabio 2001/3/5

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"������"NOR, ({ "ce zi"}));    
	set_weight(200);       
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
                        set("no_get",1);
		set("long","������Ż������������ӵ������ᡣ(read)\n");
		set("material", "paper");
	  }
}
void init()
{
        add_action("do_look", "read");
        add_action("do_write","write");
}    
int do_look(string arg)
{
        object me = this_player();
        if(arg=="huaming ce"||me->query("family/family_name")=="����������")
        {
        	if(me->query("write_name"))
        	{
        		tell_object(me,"����һ����Ż������������ᣬ��¼�˻������ĵ��ӣ���ĩ������д���������----"HIR+me->name()+NOR"��\n");
        	         return 1;
        	}
        	else 
        	{
        		tell_object(me,"����һ����Ż������������ᣬ��¼�˻������ĵ��ӣ�\n�����Ȼ��û��������֣�����ֻ���Լ�������(write)��\n");        
                         return 1;
                 }        
        }
        return 1;
}        
int do_write()
{
	object me=this_player();
	if(me->query("write_name"))
        return notify_fail("�������������������Ѿ�����������ˡ�\n");
        if(me->query("family/family_name")!="����������")
	return notify_fail("��������С�쵰���������������������д����?\n");
	tell_object(me,"��С�����������ʣ��ڲ���������������֡�\n");
	set("write_name",me->query("id"));
	me->set("write_name",1);
	return 1;
}	