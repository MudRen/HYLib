// shenxing-baibian.c ���аٱ�

// written by That

inherit SKILL;

string *dodge_msg = ({
     "$nһʽ��������ˮ�������㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
     "$nһʽ��Ǳ��ҹ�С�����Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
     "$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
     "$nһʽ������Ӱ����һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
     "$nһʽ���貨΢��������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
     "$nһʽ�����ϲ�¥�������ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
     "$nһʽ�����ӳ�ˮ��������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
     "$nһʽ�����·ת�������������ݰ㼱ת����ʱһ������ӿ������$N���Զ�����\n",
     "$nһʽ�������ﲨ��������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
     "$nһʽ�����ӻ�ͷ��������ٿ�Ĵ�$N����ǰƮ��������һ˦������֮����\n",
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");
 }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
      if((int)me->query("qi") < 40 )
           return notify_fail("�������̫���ˣ����������аٱ䡣\n");
      me->receive_damage("qi", 30);
      return 1;
}
