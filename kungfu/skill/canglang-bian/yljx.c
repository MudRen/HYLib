#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 
int perform(object me, object target)
{
    string msg;
    int extra, celepower, i, skill,whippower, myexp, enemyexp,total;
    int exp_bonus,damage,damage1,damage2;
    object weapon;
    string *perform_msg = ({
        HIW "�����ڿ�"NOR WHT" �� $N����$W��׺�������գ�����$n��\n"NOR,
        HIW "������ң"NOR WHT" �� $N��Ʈҡ��$W����õ���Ӱ�ж��������ػ�����$n��\n"NOR,
        HIW "Я�׳���"NOR WHT" �� $N����$W����һ����������$n��\n"NOR,
        HIW "���߳���"NOR WHT" �� �����ѿ����ı�������$W"NOR+WHT"����������ķ���������$n��\n"NOR,
        HIW "��������"NOR WHT" �� $W"WHT"������������$n"NOR+WHT"�ζ�����ʱ�仯��һ����꣬����$n��\n"NOR,
        HIW "��ͼ����"NOR WHT" �� $N����$W"WHT"��ת���飬�ڿ��лó�һ��������׭��ӡ��$n��\n"NOR,
        HIC "���н�������ǿ��Ϣ"NOR WHT" �� $N������������ʱ���˺�һ��$W"NOR+WHT"ƽƽ����һ�Ӷ�����ȴ�޿ɵֵ���\n"NOR,
        YEL "���������Ժ������"NOR WHT" �� $Nһ������$W"WHT"��һ������ʵ���͵��ھ���������Χ��$n��\n"NOR,
        HIG "�����Ȼ"NOR WHT" �� $N���޲�������Ȼ���лó��ڶ����飬��������չʾ�ڲ�ã��ؼ䡣\n"WHT
        "$n���ɵ���������Ȼ���Ķ����ΰ��\n"NOR}); 

    weapon = me->query_temp("weapon");
    skill = me->query_skill("canglang-bian",1);   


        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");


        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á��������֡���\n");

        if (me->query_skill("canglang-bian", 1) < 300)  
                return notify_fail("��ġ����˱޷� ��δ�����磬�޷�ʩ�����������֡���\n");  

        if (me->query_skill("bibo-shengong", 1) < 250)  
                return notify_fail("��ı���������Ϊ�������޷�ʩ�����������֡���\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("�����õĲ��ǡ����˱޷� ����ʩչ�������������֡���\n");  

        if (me->query("neili") < 900)
                return notify_fail("��������������޷�ʹ�á�������������\n");

    if( !target ) target = offensive_target(me);
    if( !target
        ||!target->is_character()
        ||!me->is_fighting(target) )
        return notify_fail(WHT"���������֣�"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
    celepower = me->query_skill("whip"); 
    
    exp_bonus = (me->query("combat_exp")-3000000)/6000000*celepower;
    if (exp_bonus<0) exp_bonus=0;
    if (exp_bonus>celepower) exp_bonus=celepower;
    
    damage = celepower+skill;
    
    myexp = me->query("combat_exp");
    enemyexp = target->query("combat_exp");
        message_vision(WHT"$N�ı޷�һ�䣬��ʽչ�������ܲ���Ũ�ƣ��꽫��δ�䣬������δ��\n"HIC"ʹ���������Ƶ��ռ�ɱʽ  ��  ���������֣ݣ���\n\n"NOR, me);
        for(i=0;i<9;i++)
        {
                msg = perform_msg[i];
                msg = replace_string(msg,"$W", weapon->name()+WHT);
                if (skill >= i * 20+10) {
                        if (i>6 && userp(me)&& (me->query_skill("whip")<300)) {
                                me->start_busy(2+i/2);
                                if (!random(1 + 8*i -i*i) && i!=8 ) 
                                        tell_object(me, YEL"\n����ñ޷��ƺ�����Ƿ��Ȼ������һ���ǳɡ�\n"NOR);
                                return 1;       
                        }
                        message_vision("\n"+msg,me,target);
                        if (random(myexp)/150*celepower*(i/2+1)> enemyexp) {
                                message_vision("\n"MAG+weapon->name()+MAG"����һ˿˿���ĵ��Ϲ⣬����$n"NOR+MAG"����... ...\n"NOR, me, target);
                                damage1 = damage+ random(damage)*3/2;
damage2=damage1+ (int)me->query_skill("whip")+100; 
//                              total= damage1+total;
//                              message_vision(HIW"\t\tdamage is "+(string)(total)+" .\n"NOR,me);

                                target->receive_damage("qi", damage1);
                                target->receive_wound("qi",damage1);
                                target->receive_damage("jing", random(damage1/2));
                                target->receive_wound("jing",10 + random(celepower/2));
                                COMBAT_D->report_status(target);
                                COMBAT_D->win_lose_check(me,target,1);
                        if (i==8)       {
                                        message_vision(HIG"$N"+HIG"�������ƣ������������Ϊһ�壬������и�ɻ���\n"NOR, me);
                                        me->start_busy(5);
                                        if ( target->is_busy()) target->start_busy(5);
                                           if ( !target->is_busy() ) target->start_busy(2);
                                        return 1;                       
                                        }       
                        } else 
                                message_vision(HIG"$N��������������$n�ı�Ӱ��\n\n"NOR,target,me);
                                                        
                }
        }
                i= (skill-10)/20-1;
                me->add("neili", -580);
                me->start_busy(4);
                return 1;       
                
} 

