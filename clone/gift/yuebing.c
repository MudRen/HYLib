// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *nm1_jp =({
"�����±�","��ɳ�±�","�����±�","֥���±�","�����±�","�����±�","�������±�","�����±�","��Ƥ�±�","��Ƥ�±�",
"��Ҷ�±�","Ҭ���±�","��ζ�±�","ҩ���±�","�����±�","�����±�","�����±�","Ҭ���±�","ˮ�������±�","���������±�",
"������±�","ˮ���±�","�����±�","ˮ���±�",
});
string *nm2_jp =({
"yue bing","yue bing",
});
void create()
{
int i = random(sizeof(nm1_jp));
	set_name(order[random(13)]+nm1_jp[random(sizeof(nm1_jp))]+NOR,({nm2_jp[0]}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ư�����±���\n");
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");
set("liwu",1);
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 1);
set("no_steal",1);
set("no_beg",1);
set("eat",5);
    set("no_put",1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	int exp,pot,score;
object corpse;
        object me = this_player();
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy())
	return notify_fail("����æ���أ�\n");

if (query("eat")>1)
{
message_vision(HIW "$N����һ��"+query("name")+HIW"�óԼ���!\n" NOR, me);
me->add("food",10);
me->start_busy(2);
add("eat",-1);
}
else
{
        this_player()->start_busy(50);

//	exp = 88888+random(8888);
	exp = 888+random(888);
	             pot = exp*2/3;
             score = random(20)+10;
        me->add("max_neili", 8);
        me->add("combat_exp", exp);
        me->add("potential", pot);
tell_object(me,HIY"�㱻�����ˣ�8����������\n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n" +
            chinese_number(score)+"�㽭������\n"NOR);

        message_vision(HIW "$N����һ��"+query("name")+HIW"�óԼ��ˣ�ֻ������������ԴԴ��������������һ�����Ƶ�!\n" NOR, me);
/*
if (me->query("weapon/lv") &&
(int)me->query("weapon/lv",1)<100)
{
  me->add("weapon/lv",2);
if (me->query("weapon/lv",1)>100)
me->set("weapon/lv",100);
message_vision(HIW"$N�����������ȼ������ˣ����µ�½����Ч!!\n"NOR, this_player());
}
if (me->query("jia/lv")&&
me->query("jia/lv",1)<150)
{
  me->add("jia/lv",2);
if (me->query("jia/lv",1)>150)
me->set("jia/lv",150);
message_vision(HIW"$N��������µȼ������ˣ����µ�½����Ч!!\n"NOR, this_player());
}
me->delete("last_getzhen");
message_vision(HIW"$N�ٴλ��������Ļ��ᣡ\n"NOR, this_player());
*/
	destruct(this_object());
}
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
