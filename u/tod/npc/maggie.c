// By Batman @ Freedom Studio 2001/6/6

inherit NPC;
#include <ansi.h>

int chatmsg();
int mz();
int here();
int rumors();
int batman();
int maggie();
int ada();
int soledad();
int jane();
int doma();
int text_draw();
int text();
int draw();
int dragon();
int tiger();
int phoenix();
int turtle();

int sword();
int skills();
int jade();
int heal();

void create()
{
        set_name("������Ů", ({ "red girl","red","girl" }) );
        set("gender", "Ů��" );
        set("age", 24);
        set("int", 30);
        set("str",60);
        set("per", 35);
        set("long",
"����һ�����ź��µ���Ů������������������ʤѩ���������ˣ���һͷ��
��Ҳ�Ƶĳ�����һֱ�������䡣����Цӯӯ�ؿ����㣬ˮ��������������
����
"
                );
        create_family("���ɸ�", 2, "��Ů");
        set("qi", 4500);
        set("max_qi", 4500);
        set("jing", 2000);

        set("max_jing", 2000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 120);
        set("combat_exp", 9999999);

        set("chat_chance", 1);
        set("chat_msg", ({
        (: chatmsg :),
        }) );

        set("inquiry", ([
                "name" : (: mz :),
                "���" : (: mz :),
                "qing er" : (: mz :),
                "maggie" : (: maggie :),
                "����" : (: maggie :),
                "batman" : (: batman :),
                "�����е�" : (: tod :),
                "ada" : (: ada :),

                "soledad" : (: ada :),
                "����" : (: ada :),
                "����" : (: soledad :),
                "lan er" : (: soledad :),
                "ӱ��" : (: jane :),
                "xiao ying" : (: jane :),
                "С��" : (: doma :),
                "xiao ma" : (: doma :),
                "����" : (: sword :),
                "����" : (: sword :),
                "�ֻ�" : (: text_draw :),
                "��" : (: text :),
                "text" : (: text :),
                "��" : (: draw :),
                "drawing" : (: draw :),
                "����" : (: dragon :),
                "dragon" : (: dragon :),
                "�׻�" : (: tiger :),
                "tiger" : (: tiger :),
                "��ȸ" : (: phoenix :),
                "phoenix" : (: phoenix :),
                "����" : (: turtle :),
                "turtle" : (: turtle :),

                "here" : (: here :),
                "���ɸ�" : (: here :),
                "rumors" : (: rumors :),
                "�书" : (: skills :),
                "����" : (: jade :),
                "��ȸ����" : (: jade :),
                "ʹ" : (: heal :),
                "����" : (: heal :),
                "�ⶾ":"�ж���ô���ⶾ�ҿɲ��ᣬ����ӱ��ɣ�",
                "�ƶ�":"�ж���ô���ⶾ�ҿɲ��ᣬ����ӱ��ɣ�",
        ]));

        setup();
        carry_object(__DIR__"obj/r_cloth")->wear();
        carry_object(__DIR__"obj/p_pei")->wear();
        carry_object(__DIR__"obj/zhuxiao")->wield();
}

void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )

        {
                remove_call_out("welcome");
                call_out("welcome", 1, ob);
        }
}

void welcome(object ob)
{
        if( !ob || environment(ob) != environment() )
                return;
        if ((string)this_player()->query("id") == "tod") 
        {
                command("say ����ү�����������");
                message_vision("$N���˵�����$n�Ļ��\n",this_object(),this_player());
        }
        else
        {
                if ((string)this_player()->query("id") == "maggie")
                        command("say ����㣬������������ү������߶�����أ�");
                else
                {
                        if ((string)this_player()->query("id") == "ada")
                                command("say �����㣬������������ү�������أ�");

                        else command("say �й�͵���");
                }
        }
}

int chatmsg()
{
        command("giggle");
}

int mz()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                set("title",HIR"ǧ������"NOR);
                set_name("���",({"qing er","qing"}));
                command("say ����ү�������Ѱ�����ˡ��û����û�Ӵ~~~ \n");
                message_vision("$N������$n������������\n", this_object(), me);
        }
        else
        {

                if ((string)me->query("id") == "maggie")
                {
                        command("say ����㣬������������ô��"); 
                        set("title",HIR"ǧ������"NOR);
                        set_name("���",({"qing er","qing"}));
                }
                else
                {
                        if ((string)me->query("id") == "ada")
                        {
                                command("say ��������������ô��");
                                set("title",HIR"ǧ������"NOR);
                                set_name("���",({"qing er","qing"}));
                        }
                        else command("say �˼ҵ������ǹ���ү��ȡ�ģ�ֻ�й���ү�ܽУ�");
                }
        }
        return 1;
}

int here()
{
        command("xixi");

        command("say ����������ǹ���ү�����ɸ�ѽ��");
        return 1;
}

int rumors()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod")
        {
                command("say ��˵����ү����������ʶ�˺ö�Ư����Ů���ӣ��ǲ������ѽ��");
                message_vision("$NС��һལ������Ĳ����ˡ�\n", this_object());
        }
        else
                command("say ����û��Ү��" + RANK_D->query_respect(me) + "��ʲô��Ȥ������˵���˼�������");
        return 1;
}

int batman()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 

        {
                command("say Ŷ����˵�ľ����Ǹ���������Ů���Ӷ����С��ѽ��");
                message_vision("$N����$nЦ�û�֦�Ҳ���\n", this_object(), me);
        }
        else
        {
                if ((string)me->query("id") == "maggie")
                        command("say ����������㣬�������ǹ���үѽ��"); 
                else
                {
                        if ((string)me->query("id") == "ada") 
                                command("say �����������㻹�ǵ�������ǹ���ү��ѽ��");
                        else
                        {
                                command("say ���������ǹ���ү����������е��");
                                message_vision("$N�������Ŀ���$n��\n", this_object(), me);
                        }
                }
        }
        return 1;
}

int maggie()

{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                command("say ����ү�������������������������ߣ�\n");
                message_vision("$N��Ƥ������ָ��$n�����Ϲ�����ȥ��\n", this_object(), me);
        }
        else
        {
                if ((string)me->query("id") == "maggie") 
                        command("say �š�������˵�����Ǹ�ס�ڸ��ڣ������ǹ���ү��˼ҹ��Ĵ���Ůô������");
                else
                {
                        command("say ����������ѽ������ס�ڸ��ڣ��������ǲ����������ô��ȥ�ġ�");
                        message_vision("$N��ͷһƲ��ֻ�˿�����ķ羰��\n", this_object(), me);
                }
        }
        return 1;
}

int ada()
{

        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say ����ү�������������Ϊʲô��ȥ�����أ���������Ǹ���Ů��Ӵ��\n");
        else
        {
                if ((string)me->query("id") == "ada")
                        command("say ������ѽ����Ȼ���Щ��û���ˣ�С��Ҳ�����������ѽ��"); 
                else
                {
                        command("say �����������ѽ������ס�ڸ��ڣ�����ֻ�й���ү֪����ôȥ������Ӵ��");
                        message_vision("$N����һ��������Ц����\n",this_object());
                }
        }
        return 1;
}

int soledad()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 
                command("say Ӵ������ү������Ҳ�ϲ����ˣ�������Ҫ�ޱ�����ѽ��\n");

        else
                command("say �������������������е�һ������µó����ĸ���");
        return 1;
}

int jane()
{
        object me, ob, obj;
        me = this_player();
        ob = this_object();
        if (present("white girl", environment(ob)) || present("xiao ying", environment(ob)))
                command("say ӱ�㲻�����Ƕ��");
        else
        {
               if ((string)me->query("id") == "tod")
                {
                        command("say ӱ����");
                        message_vision("$N������ӱ��~~����ү�����ţ�\n����������һ������Ů��ƮȻ������\n", ob);
                }
                else
                {
                        command("say ����������ӱ����");
                        message_vision("$N������ӱ��~~\n����������һ������Ů��ƮȻ������\n",ob);

                }
               if (((obj = find_living("white girl")) || (obj = find_living("white girl"))) && (sizeof(children("/u/tod/npc/jane")) > 1))
                {
                        message_vision("$N����ææ���뿪�ˡ�\n", obj);
                        obj->move(environment(ob));
                }
                else
                {
                        obj=new(__DIR__"jane");
                        obj->move(environment(ob));
                }
        }
        return 1;
}

int doma()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say С�겻�����Ƕ�����������Ը�������˵�ɣ�");
        else
                command("say ������С����������е�һ������µó����ĸ���");

        return 1;
}

int text_draw()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
        {
                command("say ֪����������ү���ֻ�������Ҳ�����������");
                message_vision("$N��Ƥ�ذ��˸�������\n",this_object());
        }
        else
                command("say �ֻ�����ֻ�ź��ү����ӣ���Щ�������ܵ��¶���");
        return 1;
}

int text()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say ����үд����ʲôѽ�������Ӵ��");

        else
                command("say �������ǹ���ү��ī����");
        return 1;
}

int draw()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 
        {
                command("say ����ү������ÿ�������Ҳ���˼һ�һ����");
                message_vision("$N��$n���˸����ơ�\n", this_object(), me);
        }
        else command("say �������������ǹ��ӻ��ġ�");
        return 1;
}

int dragon()
{
        object me;
        me = this_player();
       if ((string)me->query("id") == "tod") 

                command("say �ǵ�����ʲô����ѽ������ү�����˼���~~~~~~");
        else command("say �����������ɸ�����ܣ���--��--��--��--");
        return 1;
}

int tiger()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say �ǵ�����ʲô����ѽ������ү�����˼���~~~~~~");
        else command("say �����������ɸ�����ܣ���--��--��--��--");
        return 1;
}

int phoenix()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say �ǵ�����ʲô����ѽ������ү�����˼���~~~~~~");
        else command("say �����������ɸ�����ܣ���--��--��--��--");
        return 1;

}

int turtle()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say �ǵ�����ʲô����ѽ������ү�����˼���~~~~~~");
        else command("say �����������ɸ�����ܣ���--��--��--��--");
        return 1;
}

int sword()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say ����ү���˴��彣�");
        else
                command("say �������ǹ���ү���彣����ɱ�����⡣");
        return 1;
}


int skills()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say �˼Һܹԣ����춼����Ŷ��");
        else
                command("say �˼ҵ��书���ǹ���ү�̵ģ�����ү���书����ˡ�");
        return 1;
}

int jade()
{
        object me;
        me = this_player();
        if ((string)me->query("id") == "tod") 
                command("say ����ү�͵Ķ������˼���Ȼ�����������ඣ�");
        else command("say ���������ǹ���ү�͸��˼ҵġ�");
        return 1;
}

int accept_fight(object me)
{

        if ((string)me->query("id") == "tod")
        {
                command("say ����������ү�ǲ�������û����˼Ҷ���ѽ��");
                message_vision("$N������$n������������\n",this_object(),me);
        }
        else
        {
                if ((string)me->query("gender")=="����") 
                {
                        command("say �ߣ���׼����û����˼Ҷ������˼ҲŲ��ϵ��أ�");
                        message_vision("$N�ݺݵذ���$nһ�ۡ�\n", this_object(), me);
                }
                else command("say ��ʹҮ���˼Ҳ�����");
        }
        return 0;
}

void attempt_apprentice(object me)
{
        if ((string)me->query("id") == "batman") 
        {
                command("say ����ү��ȡЦ�˼��ˡ�");
                message_vision("$N��$n����һ����\n", this_object(), me);

        }
        else command("say ���ɸ���书�ɲ��⴫Ŷ��");
}

int heal()
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if (((int)me->query("eff_qi") < (int)me->query("max_qi"))
                || ((int)me->query("eff_jing") < (int)me->query("max_jing")))
                {
                        command("say ������ô�������ơ�");
                        message_vision(HIW"$N��$n����ʯ̨��һ���Ū��\n"NOR, ob, me);
                        me->set("eff_jing", me->query("max_jing"));
                        me->set("jing", me->query("max_jing"));
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi", me->query("max_qi"));
                        tell_object(me, HIG"��Ȼ�ַ����죬ȴ�������˵���������á�\n"NOR);
                }       
        else command("say �˼ҿ����޲����˵ģ���������ƭ�ˡ�");
        return 1;

}
