// puliu.c �¼����ƹ����ٲ�

#include <ansi.h>


// ����
private void do_bonus(object room)
{
        object *obs;
        object ob;
        string msg;
        int lvl;
        int r;
        int p_bonus,s_bonus,i;
        obs = all_inventory(room);
        //obs = filter_array(obs, (: playerp($1) && living($1) :));
//                CHANNEL_D->do_channel(this_object(), "rumor",
//                                      "��˵�ƹ����������ȣ��澰�Ƿ�����������̾�۲��ѡ�");

        if (sizeof(obs) < 1)
                return;

        r = random(365);
        if (r == 0)
        { 
      	        	msg = HIG "����Ȼ��ۡ��ƹ����ٲ�\n"NOR;
                msg += HIR "ֻ����¡¡�����������������������������ҡ����̧ͷ��ȥ��ֻ��\n"
                          "�����лƹ����ٲ������Ų������������Ҫ�ˡ�ˮ����к�����ƾ��ˣ�\n" NOR;
                msg += HIG "�������ļ����ٲ�������Ϊ������������̾���ѣ���"
                           "�в�����������ѧ�ĵ���\n" NOR; 
                 message("vision", msg, obs);           
 for ( i = 0 ; i < sizeof(obs); i++)  // ����Ǳ�ܻ����ڹ���Ǳ��
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 1000 + random( 500 );
			s_bonus = 800 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("force", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("force", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("force", lvl + 1);

                }

                message("vision", msg, obs);

                // ��¼�¼�
                

                CHANNEL_D->do_channel(this_object(), "rumor",
                                      "��˵�ƹ����������ȣ��澰�Ƿ�����������̾�۲��ѡ�");
        } else 
        if (r < 250) 
        {
                msg = HIY "һ���¡��¡�ĵ�������������̧ͷһ����ֻ���������ٲ�������������\n" NOR;
                switch (random(3)) 
                { 
                case 0: 
                        msg += HIY "������׳�����������㲻����̾������ν������ֱ"
                                    "����ǧ�ߣ�������������졹����\n" NOR; 
                        break; 
                case 1: 
                        msg += HIY "��������һϯ���ҵİ�����������磬��ض�����Ϊ֮ʧɫ��\n" NOR; 
                        break; 
                default: 

                        msg += HIY "����ֱ��ˮ��й��һ�㣬ˮ���Ľ���\n" NOR; 
                        break; 
                } 
                msg += HIG "�����ŷ���ֱ�µ�ˮ�٣��㲻�ɵø�̾��Ȼ�컯�������"
                           "��Ȼ����ѧҲ����һ����ᡣ\n" NOR; 
 for ( i = 0 ; i < sizeof(obs); i++)  // ����Ǳ�ܻ����ڹ���Ǳ��
                {
                	if( !living(obs[i]) || !userp(obs[i]) ) continue;
			p_bonus = 600 + random( 500 );
			s_bonus = 300 + random( 500 );
			obs[i]->add("potential", p_bonus);
			obs[i]->add("score",s_bonus);
                        
			lvl = obs[i]->query_skill("force", 1);
                        if (lvl >= 50 && lvl< 300 )
                               	obs[i]->set_skill("force", lvl + 10);
                        else if ( lvl >= 300 )
                               	obs[i]->set_skill("force", lvl + 1);

                }
 
                message("vision", msg, obs);

                // ��¼�¼�
                
        } else
        {
                switch (random(3))
                {
                case 0:
                        msg = WHT "������������������\n" NOR;
                        break;
                case 1:
                        msg = WHT "�������ǲ�������ǿ�����ơ�\n" NOR;
                        break;
                default:
                        msg = WHT "��������С����ˮ���������ˣ������������������Զ��\n" NOR;
                        break;
                }
                msg += HIG "�����д��ʧ����\n" NOR;

                message("vision", msg, obs);
        }
} 
 
// �¼����� 
void trigger_event() 
{ 
        object room; 
        // �ƹ������� 
        if (objectp(room = find_object("/d/kunming/pubu"))) 
                do_bonus(room); 
 
       // create_event(); 
} 


void create() 
{ 
	seteuid(getuid()); 
	message("channel:sys", HIR"����Ȼ��ۡ��ƹ����ٲ���\n"NOR, users());
	trigger_event();
}

// ���� 
string query_detail(string topic) 
{ 
        switch (topic) 
        { 
        case "�ƹ�������": 
                return "�ƹ����ٲ�ˮ���ļ���ʱ�м������ȣ����Ǻ����ľ��ۡ�\n"; 
 
        case "�ƹ����ٲ�": 
                return "����Ļƹ����ٲ���Ȼ������ˣ���������׳�ۡ�\n"; 
        }
} 
