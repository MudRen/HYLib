//Cracked by Kafei
// shinu.c ����ɽׯ��Ů

inherit NPC;

void create()
{
        set_name("�����輧", ({ "baiyi wuji","wuji","ji" }));
        set("long", "һ����ɫ��������Ů�ӣ��𷢱��ۣ��߱���Ŀ��������Ů�Ӵ���ͬ��\n����ò��������̬���ģ����Զ��ˡ�\n");
        set("gender", "Ů��");
        set("age", 22);

        set_skill("hand", 10);
        set_skill("dodge", 10);
        set_skill("parry", 10);
        set_skill("force", 10);

        set("str", 20);
        set("int", 22);
        set("con", 20);
        set("dex", 20);

        set("max_neili", 200);
        set("combat_exp", 3000);

        set("attitude", "peaceful");
	set("chat_chance", 5);
        set("chat_msg", ({
	"�����輧ǰ������������������������Ѽ�������һ�����ߡ�\n",
	"�����輧˫����չ��������ָ��������ָ�⣬ŤŤ����������һ�������ζ�����һ�㡣\n",
	"�����輧�������裬��̬�ٳ�����ö�ˣ�����˫���鸧���Σ��������½����Ͷ���ͱ��������̬��\n",
	}) );
	setup();
	carry_object(__DIR__"wcloth")->wear();
}
