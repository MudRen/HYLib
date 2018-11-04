// zhang.c ����ʦ

#include <ansi.h>

inherit NPC;

int ask_me();
int ask_hui();

void create()
{
	set_name("����ʦ", ({ "zhang tianshi", "zhang" }));
	set("age", 57);
	set("gender", "����");
	set("long", "����һλ�ɷ���ǣ���ò��Ȼ�ķ�ʦ��\n");
	set("attitude", "peaceful");

	set("str", 28);
        set("int", 35);
        set("con", 38);
	set("dex", 31);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("max_neili", 8000);

        set_skill("magic", 200);
        set_skill("taoism", 350);

        set("chat_chance_combat", 3);
	set("chat_msg_combat", ({
                "����ʦҡҡ���������������飬�����㣬̫���Ͼ��������飿\n",
                "����ʦ�����Ĵ��˼�������\n",
	}));

        set("inquiry", ([
                "����" : (: ask_hui :),
                "����" : (: ask_me :),
                "ûǮ" : "ûǮ��ȥ׬������˵ʲô��",
                "��"   : "����Ҳ��һ��������",
                "ħ��" : "ħ����ʲô���գ�",
                "����" : "�������ֺܶ����أ�������������������һ���㡣",
                "����" : "����������Ǳ�Դ���ڣ�",
                "����" : "�������������³ˣ�����Ϊ�ᡣ",
                "����" : "����ֻ�������гˣ����ǲ��ܺ͵�����ȡ�",
//                "����" : "��Ҫ�ǲ����ҿ��԰��㿴��(show)������Ҫ��ʲô��Ʒ��",
        ]));

	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
        add_action("do_show", "show");
        add_action("do_summon", "summon");
}

int ask_me()
{
        command("heihei");
        command("say ��ֻ������������⣬Ѱ������Ī�ᣡҪ"
                "�㱾�˵ģ��ҿɲ��ܰ��������£�");
        tell_object(this_player(), GRN "����ʦ�����������˵��"
                    "���Ҫ������ó������ҿ���(show)��\n" NOR);
        return 1;
}

int ask_hui()
{
        command("sigh");
this_player()->delete("diablo");
this_player()->save();
        tell_object(this_player(), GRN "����ʦ�����������˵��"
                    "���½�����Ϸ����������������¿��⣬�ű�ʯ�ˣ�\n" NOR);
        return 1;
}

int do_summon(string arg)
{
        if (! wizardp(this_player()))
        {
                command("say ��������ǰϹץ��ʲô���������ȥ��");
                return 1;
        }

        return 0;
}

int do_show(string arg)
{
        object money;
        object ob;
        object me;
	string type;

        if (! arg)
                return notify_fail("��Ҫ����ʲô������\n");

        me = this_player();
        if (! objectp(ob = present(arg, me)))
                return notify_fail("������û�����ֶ�����\n");

        if (ob->query("equipped"))
                return notify_fail("���Ƚ��" + ob->name() + "��װ����˵��\n");

        message_vision("$n�ó�һ" + ob->query("unit") + ob->name() +
                       "��$N˵�������а���...��\n",
                       this_object(), me);

        if (ob->query("money_id"))
        {
                command("say ������Ǯ��ʲô�����׸�����Ǿ͸��Һ��ˡ�");
                return 1;
        }

        if (! me->query_temp("paid/����ʦ", 1))
        {
                command("heihei");
                command("say ��...��ôҲ���е���˼��˼�ɣ���"
                        "˵һǧ���ƽ���ô������Ȼ��Щ��Ҳ�����ԡ�");
                return 1;
        }

        if (!ob->query("max_sockets"))
        {
                command("say Ŷ���ҿ������ܿ��⣡");
                return 1;
        }
	if (mapp(ob->query("weapon_prop")))
		type = "weapon";
	else if (mapp(ob->query("armor_prop")))
		type = ob->query("armor_type");


if (type=="finger")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 1
&& me->query("combat_exp") < 10000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 2
&& me->query("combat_exp") < 20000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 3)
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }

}
if (type=="weapon")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 3
&& me->query("combat_exp") < 10000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 4
&& me->query("combat_exp") < 20000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 5)
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }

}
if (type=="cloth")
{
if (me->query("diablo/" + type + "/sockets/max",1) >= 3
&& me->query("combat_exp") < 10000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 4
&& me->query("combat_exp") < 20000000 )
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }
if (me->query("diablo/" + type + "/sockets/max",1) >= 5)
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }

}
//        if (ob->query("sockets/max") >= ob->query("max_sockets"))
//        {
//                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
//                return 1;
//        }

        if (ob->query("sockets/max",1) >= 5)
        {
                command("say Ŷ���ҿ��������Ѿ�����Ҫ�ڿ����ˣ�");
                return 1;
        }

        message("vision", HIM + name() + "�ӿڴ�������һ�Ż�ɫ"
                                "�ķ�ֽ������������ľ����"
                                "���Ƿ�ֽ��ȼ�ˣ�ɨ��" + ob->name() + HIM "��Ȼ"
                                "������ľ�����ˣ������㵸�����������дʣ�"
                                "��̫���Ͼ��������ɴ����˵��һ�����н���"
                                "�ȵ�����������\n" NOR, environment());
        message_vision("��⻮��һ���⻪��$N���˷�����Ҳ��֪��������ô���¡�\n",
                       me);
        command("say ���ˣ����ˣ���������ˡ�");
        me->delete_temp("paid/����ʦ");
	if (mapp(ob->query("weapon_prop")))
		type = "weapon";
	else if (mapp(ob->query("armor_prop")))
		type = ob->query("armor_type");
	me->set("diablo/" + type + "/id", ob->query("id"));
	me->add("diablo/" + type + "/sockets/max", 1);
	seteuid(ROOT_UID);
	reload_object(ob);
        seteuid(getuid());
        return 1;
}

int accept_object(object who, object ob)
{
        if (! ob->query("money_id"))
        {
                command("say �������ҿ�ûɶ��Ȥ��");
                return 0;
        }

        if (ob->value() < 10000000)
        {
		command("shake " + who->query("id"));
                command("say �������Ǹ���������ô��");
                return 0;
        }

        command("say ��������Ҳ���е����⣬�Ҿ����㿪һ�ι�ɣ�");
        who->set_temp("paid/����ʦ", 1);
//      destruct(ob);
        return 1;
}

void fight_ob(object ob)
{
        ::fight_ob(ob);
        message_vision("$N��Цһ��������������ͷ��ʲô�˶��С���˵������һָ$n��\n",
                       this_object(), ob);
        ob->unconcious();
}

int accept_fight(object who)
{
        command("say û��Ȥ��");
        return 0;
}

int accept_ansuan(object who)
{
        return notify_fail("����밵�㣬������ǰһ��������̫�����\n");
}

void receive_damage(string type, int n)
{
        return;
}

void receive_wound(string type, int n)
{
        return;
}
