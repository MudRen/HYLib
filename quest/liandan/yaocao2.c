// yaocao.c ҩ��  
// ����lywin 2000/6/15

#include <ansi.h>
inherit ITEM;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create() 
{
string file;
string *roomlines;
string location;
file = read_file("/clone/medicine/yaocainame");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
        //set_name(HIG "���ҩ��" NOR,({"yao cao", "yao"}));
set_name(order[random(13)]+"����"+location+NOR,({"yao cao", "yao"}));
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_put",1);
		set("yaocao",1);
		set("lev",2);
                set("long", "����һ�������������е�������ҩ��һ���˶������ϳ��Ӳݡ�\n");
             }
        setup();
}



void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if(!present(this_object(), me))
		return notify_fail("��Ҫ��ʲô��\n");
	if( me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	me->add("food",20);
	me->add("water",20);
	write("���������ڰ�"+this_object()->query("name")+"������ȥ��\n");
	destruct(this_object());
	return 1;
}
