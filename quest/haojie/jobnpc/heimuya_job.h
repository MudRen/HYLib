#include <ansi.h>;
void init()

{        object ob,me,what;

        ::init();

        ob = this_player();

        me = this_object();

        if( living(ob) && !is_fighting() && living(me) && !is_fighting(ob)
        && !ob->query_temp("no_kill"))
        {

                if( 1 )

                        {


if (userp(ob) && ob->query("combat_exp") > 1800000
&& ob->query("family/family_name")!= me->query("family/family_name"))
{
ob->start_busy(2);
command("hit "+ob->query("id"));
                                me->fight_ob(ob);
                                ob->fight_ob(me);
                                fight_ob(ob);
                                ob->fight(me);
me->start_busy(1);
if (random(3)==0)
                                say(HIR+me->query("name")+

                                "�ٺ���Ц�˼�����������֮����������"+me->query("hated")+"���˴Ӵ��ڽ�������ʧ��\n�ҿ�"+ob->query("name")+"���ǹԹԵ����־��ܰ�!\n\n"NOR);
}
else if (!ob->query_temp("no_kill")
&& !userp(ob)
&& !ob->query("hated")
&&  ob->query("id")!="renwu shi"
)
{
ob->start_busy(2);
command("kill "+ob->query("id"));
                                me->kill_ob(ob);
                                ob->fight_ob(me);
                                kill_ob(ob);
                                ob->fight(me);
me->start_busy(1);
if (random(3)==0)
                                say(HIR+me->query("name")+

                                "�ٺ���Ц�˼�����������֮����������"+me->query("hated")+"���˴Ӵ��ڽ�������ʧ��\n�ҿ�"+ob->query("name")+"���ǹԹԵ����־��ܰ�!\n\n"NOR);
}
                        }else{

                remove_call_out("greeting");

                call_out("greeting",1,ob,me);

                }

        }

        if(!me->query("have_init")){

                me->set("have_init",1);

                call_out("dest_me",480,me);

        }

}

void greeting(object ob,object me)

{

        if( !ob || environment(ob) != environment() ) return;

        switch( random(5) ) {

                case 0:

                        say(me->query("name")+"��ݺݵ�˵����ɱ����һ�����Ҳ��Ҫ��!!\n");

                        break;



        }

}

void dest_me(object me)

{

        if( living(me) && !is_fighting(me))

        {

                say(HIR+me->query("name")+

                                "��Ȼ�����߽е�������ȷŹ����ǣ��´��پ����ߵ͡�\n˵��һ��ת����ʧ����Ӱ���١�\n"NOR);

                destruct(me);

        }else{

        remove_call_out("dest_me");

        call_out("dest_me",5,me);

        }

}