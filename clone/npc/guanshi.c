#include <ansi.h>
// liumang.c ��å
inherit NPC;
string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "�����ž�" NOR,
        BLU "��ͨƤë" NOR,
        HIB "��֪һ��" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        YEL "����С��" NOR,
        YEL "����С��" NOR,
        YEL "����Ѿ�" NOR,
        HIY "�������" NOR,
        HIY "��Ȼ����" NOR,
        HIY "�������" NOR,
        MAG "���д��" NOR,
        MAG "���д��" NOR,
        MAG "�������" NOR,
        HIM "����似" NOR,
        HIM "�����뻯" NOR,
        HIM "��Ȼ��ͨ" NOR,
        RED "�Ƿ��켫" NOR,
        RED "����Ⱥ��" NOR,
        RED "������˫" NOR,
        HIR "һ����ʦ" NOR,
        HIR "������" NOR,
        HIR "����Ⱥ��" NOR,
        WHT "��������" NOR,
        WHT "��������" NOR,
        HIW "�޿�ƥ��" NOR,
        HIW "��������" NOR,
        HIY "�"HIR"�ɲ�" NOR,
        HIC "����" HIW "����" NOR, 
        HIY "��" HIC "��" HIW "��" HIR "��" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        BLU "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "ƽ������" NOR,
        YEL "��������" NOR,
        YEL "������" NOR,
        HIY "����С��" NOR,
        HIY "�������" NOR,
        MAG "��Ȼ����" NOR,
        HIM "���д��" NOR,
        RED "��Ȼ��ͨ" NOR,
        HIR "�������" NOR,
        CYN "����Ⱥ��" NOR,
        HIC "һ����ʦ" NOR,
        HIW "������˫" NOR,
        HIC "���" HIW "���" NOR,  
        HIY "�" HIR "�ɲ�" NOR,
        HIY "��" HIC "��" HIW "��" HIR "��" NOR
});

string skill_level(string, int);

void create()
{
	set_name("���ڹ���", ({ "guanshi", "shi" }));
	set("gender", "����");
	set("age", 19);
	set("long", "����һ�����ڹ��£�֪���ܶ�������������(datan)��������Ҫ�鱨��\n");
	
	set("combat_exp", 5000);
	set("shen_type", 1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 420);
        set_skill("parry", 420);
	set_skill("dodge", 420);
	set_temp("apply/attack", 500);
	set_temp("apply/defense", 500);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}

int init()
{
        add_action("do_check","datan");
}

int do_check(string arg)
{
	object ob,gold, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost, check_level;
        object me=this_player();
	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("������û�н��ӡ�\n");

        if((int) gold->query_amount() < 1)
        return notify_fail("������û����1�����ӡ�\n");
        gold->add_amount(-1);

	if ( !arg )
		return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

        if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
if (wizardp(ob)) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");
	if ( ob == me )
		return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ��ļ��ܣ�\n");
        if (wizardp(ob)&& userp(ob))
                return notify_fail("��Ҫ����˭�ļ��ܣ�\n");


	tell_object(me, "������ǰȥ��С���������" + man->name() + "��������" + ob->name() + "����� ...\n\n");
	message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
		environment(me), ({ me, man }) );

	me->receive_damage("jing", 10 );

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( man->name() + "�����㣺 " + ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( man->name() + "�����㣺 " + ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	i = random(sizeof(skl));

	printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "��"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],
	);

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 10;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}
