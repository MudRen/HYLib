#include <dbase.h>
#include <login.h>


int prevent_learn(object me, string skill)
{
	int betrayer,shen;

	if( betrayer = me->query("betrayer") ) {
	if (0) {
		if( me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) {
			message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ����ʦ�ŵ����� ...��\n",
				this_object(), me );
			//command("say �� .... ʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
			return 1;
		}
	}
	}
shen=this_object()->query("shen");

if (shen > 800000) shen=800000;
if (shen < -800000) shen=-800000;

                if (shen < 0 && me->query("shen") > shen)
{
			message_vision("$N˵��,�ߣ������������Ĵ�����֮������"
                               "������ѧ���书Ҳ"
                               "�����á�",
				this_object(), me );

//command("say �ߣ������������Ĵ�����֮������������ѧ���书Ҳ�����á�");
return 1;
}

                if (shen > 0 && me->query("shen") < shen)
{
			message_vision("$N˵���ߣ���Ŀǰ�������������²������������书��ʱ�����ܽ���"
                               "���㡣",
				this_object(), me );
//command("say �ߣ���Ŀǰ�������������²������������书��ʱ�����ܽ��ڸ��㡣");
return 1;
}

		if( me->query_skill(skill, 1) >= 200 && (int)me->query("mpgx")+200<= me->query_skill(skill, 1) ) {
			message_vision("$N˵��,��Ϊ" + this_object()->query("family/family_name") +
                       "�����Ĺ��ײ������������书��ʱ�����ܴ��㡣\n",
				this_object(), me );
//command("say �ߣ���Ϊ���������Ĺ��ײ������������书��ʱ�����ܴ��㡣��");
			return 1;
		}

	if( !me->is_apprentice_of(this_object())
	&&	(int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 
&& !query("pubmaster")	) {

//		command("hmm");
//		command("pat " + me->query("id"));
		command("say ��Ȼ���������µĵ��ӣ����ǲ����ҵĵմ����� ....");
		command("say ��ֻ�ܽ�����Щ��ǳ�ı��Ź��������Ļ���ȥ����ʦ��ѧ�ɡ�");
		return 1;
	}

	return 0;
}
void attempt_detach(object me)
{
        if (! me->is_apprentice_of(this_object()))
        {
                command("say ��ȥ������ʦ����");
                return;
        }

        command("sigh");
        
        if (! me->query("zhuanshi"))
        {
                command("say �߰��߰ɣ����߰ɣ�����ѧ�����书���£�");

                me->skill_expell_penalty();
                me->unconcious();

                message_vision("$N������ճ��$n�ı��������"
                               "��֪����˵Щʲô��\n", this_object(), me);
                //me->add("detach/" + me->query("family/family_name"), 1);
        }
        command("say �߰��߰ɣ������ڿ����߰ɣ�");
        me->delete("family");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "��ͨ����");
}
nomask void master_accept_kill(object me)
{
        object *inv;

        inv = all_inventory(environment());
        for(int i = 0; i < sizeof(inv); i++) 
        {
                if (! inv[i]->is_character()
                || inv[i] == this_object()
                || inv[i] == me
                || userp(inv[i])
                || inv[i]->query("family/family_name") != this_object()->query("family/family_name"))
                        continue;
                else 
                {
                        message_vision(sprintf("$N��$n�ź���������%s�����ǻ�Ĳ��ͷ��ˣ�����\n\n",
                                (me->is_apprentice_of(this_object()))?
                                "������ʦ����":((me->query("family/family_name") == this_object()->query("family/family_name"))?
                                "��ͬ��ʦ����Ҫɱ":"�Ҷ�����ʦ��" )),inv[i],me );
                        inv[i]->kill_ob(me);
                        me->kill_ob(inv[i]);
                }
        }
        return;
}
