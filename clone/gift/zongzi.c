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
"��������","��������","��������","�㹽����","��Ѽ����","�㹽����","��������","��������","��ˮ����","��ɳ����",
"�ඹ����","��������","��������","��������","�缦����","�ඹ������","���ʰ�����","�޺�����","ţ������","��଼�����",
"��Ƥ����",
});
string *nm2_jp =({
"zong zi","zong zi",
});
void create()
{
int i = random(sizeof(nm1_jp));
	set_name(order[random(13)]+nm1_jp[random(sizeof(nm1_jp))]+NOR,({nm2_jp[0]}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��Ư�������ӡ�\n");
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
        this_player()->start_busy(20);

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
	destruct(this_object());
}
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
